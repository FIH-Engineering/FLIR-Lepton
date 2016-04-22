#include <QApplication>

#include "mainwindow.h"

int main( int argc, char **argv )
{
    QApplication a(argc, argv);
	
    MainWindow *mainWindow = new MainWindow();
	//added//
	mainWidget->setStyle(new QMacStyle());
    mainWindow->setWindowState(Qt::WindowFullScreen); 
    mainWindow->show();

	return a.exec();
}

