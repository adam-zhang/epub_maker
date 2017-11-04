#ifndef __MDIWIDGET__H
#define __MDIWIDGET__H

#include <QMdiSubWindow>

class MdiWidget : public QMdiSubWindow
{
	Q_OBJECT
	public:
		MdiWidget(QWidget * parent = 0);
		virtual ~MdiWidget();
	private:
		void initialize();
		
};


#endif//__MDIWIDGET__H
