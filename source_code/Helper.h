#ifndef __HELPER__H
#define __HELPER__H

class QWidget;

template<typename Dialog>
void showDialog(QWidget* parent)
{
	Dialog dialog(parent);
	dialog.exec();
}


#endif//__HELPER__H
