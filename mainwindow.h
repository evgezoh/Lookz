#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPixmap>
#include <QTimer>
#include <QMouseEvent>
#include <QDebug>
#include <QMediaPlayer>
#include <QDir>
#include <QSound>
#include "pictures.h"
#include "startmenu.h"
#include "processor.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    QGraphicsScene *scene;
    QGraphicsScene *scene2;

    QTimer *timer;
    QTimer *timerclock;

    Pictures *picture;
    Pictures *picture2;

    QMediaPlayer *player;
    QMediaPlayer *mistake; // деструктор

    QGraphicsEllipseItem *ellipse;

    void mousePressEvent(QMouseEvent * event);
    bool clickgreen(int x, int y);
    void setPoints();

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:

    void timerslot();
    void timerclockslot();
    void to_menu();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H


