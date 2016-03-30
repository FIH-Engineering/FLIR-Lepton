#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>

class QLabel;
class LeptonThread;
class QGridLayout;

class MainWindow : public QMainWindow {
    Q_OBJECT

    enum { ImageWidth = 820, ImageHeight = 440 };

    static int snapshotCount;

    QLabel *imageLabel, *templabel;
    LeptonThread *thread;
    QGridLayout *layout;

    unsigned short rawMin, rawMax;
	int maxTemp, minTemp;
    QVector<unsigned short> rawData;
    QImage rgbImage;

public:
    explicit MainWindow(QWidget *parent = 0);

public slots:
    void saveSnapshot();
    void updateImage(unsigned short *, int, int);
};

#endif // MAINWINDOW_H
