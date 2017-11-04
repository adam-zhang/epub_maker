#ifndef __CENTRALWIDGET__H
#define __CENTRALWIDGET__H

#include <QWidget>

class CentralWidget : public QWidget
{
	Q_OBJECT
	public:
		CentralWidget(QWidget* parent = 0);
		virtual ~CentralWidget();
	public:
	private:
		void initialize();
};
#endif//__CENTRALWIDGET__H
