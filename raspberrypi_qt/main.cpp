#include <QApplication>
#include <QLabel>
#include <QMacStyle>
#include <QWindowsStyle>
#include <QStyle>

#include "mainwindow.h"

int main( int argc, char **argv )
{
    QApplication a(argc, argv);

    MainWindow *mainWindow = new MainWindow();
    mainWindow->setWindowState(Qt::WindowFullScreen); 
    mainWindow->show();

	return a.exec();
}

