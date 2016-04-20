#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QTimer>
#include "GPIOClass.h"
class QLabel;
class QMessageBox;
class LeptonThread;
class QGridLayout;

class MainWindow : public QMainWindow {
    Q_OBJECT

    enum { ImageWidth = 700, ImageHeight = 440 };

    static int snapshotCount;

    QLabel *imageLabel, *maxlabel, *minlabel;
    LeptonThread *thread;
    QGridLayout *layout;
	GPIOClass* gpio17;
	QTimer *pintimer;

    unsigned short rawMin, rawMax;
    QVector<unsigned short> rawData;
    QImage rgbImage;

public:
    explicit MainWindow(QWidget *parent = 0);

public slots:
    void saveSnapshot();
    void updateImage(unsigned short *, int, int);
	void readInputPin(void);
};

#endif // MAINWINDOW_H
