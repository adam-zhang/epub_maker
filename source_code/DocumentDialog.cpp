#include "DocumentDialog.h"
#include "Configuration.h"
#include "Document.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDebug>
#include <QMessageBox>
//#include <QListView>
#include <QListWidget>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>

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
	layout->addWidget(new QListWidget);
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

void DocumentDialog::onButtonBrowse()
{
	QString text = editAddress()->text();
	if (!text.size())
	{
		QMessageBox::information(this, Configuration::applicationName(), tr("Please input address."));
		return;
	}
	Document doc(text);
	doc.contents();
}


