#include "MdiWidget.h"
#include <QTreeView>
#include <QSplitter>

MdiWidget::MdiWidget(QWidget* parent)
	: QMdiSubWindow(parent)
{
}

MdiWidget::~MdiWidget()
{
}

void MdiWidget::initialize()
{
	auto splitter = new QSplitter(this);
	splitter->addWidget(new QTreeView(splitter));
	splitter->addWidget(new QTreeView(splitter));
}
