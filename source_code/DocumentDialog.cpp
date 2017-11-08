#include "DocumentDialog.h"
#include "Configuration.h"
#include "Document.h"
#include <map>
#include <QTextCodec>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDebug>
#include <QMessageBox>
//#include <QListView>
#include <QListWidget>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>

using namespace std;

DocumentDialog::DocumentDialog(QWidget* parent)
	: QDialog(parent)
{
	initialize();
}

DocumentDialog::~DocumentDialog()
{
}

void DocumentDialog::initialize()
{
	auto layout = new QVBoxLayout(this);
	layout->addLayout(createAddressControles());
	layout->addLayout(createConntentControls());
}

QLayout* DocumentDialog::createConntentControls()
{
	auto layout = new QHBoxLayout;
	setListWidget(new QListWidget);
	layout->addWidget(listWidget());
	layout->addWidget(new QTextEdit);
	return layout;
}

QLayout* DocumentDialog::createAddressControles()
{
	auto layout = new QHBoxLayout;
	setEditAddress(new QLineEdit);
	layout->addWidget(editAddress());
	auto button = new QPushButton(tr("&Browse"));
	layout->addWidget(button);
	connect(button, &QPushButton::clicked, this, &DocumentDialog::onButtonBrowse);
	return layout;
}

static QString GbkToUtf8(const QByteArray& in)
{
	auto utf8 = QTextCodec::codecForName("UTF-8");
	return utf8->toUnicode(in);
}

void DocumentDialog::onButtonBrowse()
{
	QString text = editAddress()->text();
	if (!text.size())
	{
		QMessageBox::information(this, Configuration::applicationName(), tr("Please input address."));
		return;
	}
	Document doc(text);
	links_ = doc.contents();
	for(pair<QByteArray, QByteArray> item : links_)
	{
		listWidget()->addItem(GbkToUtf8(item.second));
	}
}


