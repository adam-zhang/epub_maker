#ifndef __DOCUMENTDIALOG__H
#define __DOCUMENTDIALOG__H

#include <QDialog>

class QLayout;
class QLineEdit;

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
	public:
		QLineEdit* editAddress()
		{ return editAddress_;}
		void setEditAddress(const QLineEdit* value)
		{ editAddress_ = value;}
};
#endif//__DOCUMENTDIALOG__H
