#ifndef __DOCUMENTDIALOG__H
#define __DOCUMENTDIALOG__H

#include <QDialog>
#include <map>

class QLayout;
class QLineEdit;
class QListWidget;

class DocumentDialog : public QDialog
{
	Q_OBJECT
	public:
		DocumentDialog(QWidget* );
		virtual ~DocumentDialog();
	private:
		void initialize();
		QLayout* createAddressControles();
		QLayout* createConntentControls();
	private slots:
		void onButtonBrowse();
	private:
		QLineEdit* editAddress_;
		QListWidget* listWidget_;
		std::map<QByteArray, QByteArray> links_;
	public:
		QListWidget* listWidget()
		{ return listWidget_;}
		void setListWidget(QListWidget* value)
		{ listWidget_ = value;}
		QLineEdit* editAddress()
		{ return editAddress_;}
		void setEditAddress(QLineEdit* value)
		{ editAddress_ = value;}
};
#endif//__DOCUMENTDIALOG__H
