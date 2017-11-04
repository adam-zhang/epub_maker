#include "MainWindow.h"
#include "Helper.h"
#include "CentralWidget.h"
#include "DocumentDialog.h"
#include <QMenuBar>
#include <QMdiArea>
#include <QStatusBar>
#include <QLabel>
#include <QTimer>
#include <QDateTime>
#include <QDebug>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
	  , clock_(0)
{
	initialize();
}

MainWindow::~MainWindow()
{
}

void MainWindow::initialize()
{
	setWindowTitle("Epub Maker");
	setCentralWidget(new CentralWidget);
	initializeMenu();
	initializeStatusbar();
	initializeToolbar();
}

inline QMdiArea* MainWindow::mdiArea()
{
	return static_cast<QMdiArea*>(centralWidget());
}

void MainWindow::initializeToolbar()
{
}

void MainWindow::createStatusControls()
{
	clock_ = new QLabel;
	QWidget* widget = new QWidget;
	QHBoxLayout* layout = new QHBoxLayout(widget);
	layout->addWidget(clock_);
	statusBar()->addWidget(widget);
}

void MainWindow::createTimer()
{
	auto timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, &MainWindow::onTimeout);
	timer->setInterval(1000);
	timer->start();
}

void MainWindow::initializeStatusbar()
{
	createStatusControls();
	createTimer();
}

void MainWindow::onTimeout()
{
	QDateTime time = QDateTime::currentDateTime();
	QString s = time.toString(Qt::ISODate);
	clock_->setText(s);
	//clock_->adjustSize();
}

void MainWindow::initializeMenu()
{
	createFileMenu();
	createEditMenu();
	createHelpMenu();
}

void MainWindow::createHelpMenu()
{
	auto menu = menuBar()->addMenu(tr("&Help"));
}

void MainWindow::createEditMenu()
{
	auto menu = menuBar()->addMenu(tr("&Edit"));
}

void MainWindow::createFileMenu()
{
	auto menu = menuBar()->addMenu(tr("&File"));
	auto action = menu->addAction("&New");
	connect(action, &QAction::triggered, this, &MainWindow::onFileNew);
}

void MainWindow::onFileNew()
{
	showDialog<DocumentDialog>(this);
}



