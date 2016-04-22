#include <QApplication>
#include <QLabel>
#include <QMacStyle>
#include <QWindowsStyle>
#include <QStyle>

#include "mainwindow.h"

int main( int argc, char **argv )
{
    QApplication a(argc, argv);
	a.setStyle(new QMacStyle);
    MainWindow *mainWindow = new MainWindow();
	//added//
	//mainWindow->setStyle(new QMacStyle());
    mainWindow->setWindowState(Qt::WindowFullScreen); 
    mainWindow->show();

	return a.exec();
}

