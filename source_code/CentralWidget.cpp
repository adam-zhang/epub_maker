#include "CentralWidget.h"
#include <QSplitter>
#include <QTreeView>
#include <QTextEdit>
#include <QHBoxLayout>

CentralWidget::CentralWidget(QWidget* parent)
	: QWidget(parent)
{
	initialize();
}

CentralWidget::~CentralWidget()
{}

void CentralWidget::initialize()
{
	QHBoxLayout* layout = new QHBoxLayout(this);
	auto splitter = new QSplitter;
	splitter->addWidget(new QTextEdit);
	splitter->addWidget(new QTreeView);
	layout->addWidget(splitter);
}
