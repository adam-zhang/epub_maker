#ifndef __MAINWINDOW__H
#define __MAINWINDOW__H

#include <QMainWindow>

class QLabel;
class QMdiArea;

class MainWindow : public QMainWindow
{
	Q_OBJECT

	public:
		MainWindow(QWidget* parent = 0);
		virtual ~MainWindow();
	private:
		void initialize();
		void initializeMenu();
		void initializeStatusbar();
		void initializeToolbar();
		void createFileMenu();
		void createEditMenu();
		void createHelpMenu();
		void createStatusControls();
		void createTimer();
	private:
		QMdiArea* mdiArea();
	private:
		QLabel* clock_;
	private slots:
		void onTimeout();
		void onFileNew();
};

#endif//__MAINWINDOW__H
