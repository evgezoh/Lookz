#ifndef STARTMENU_H
#define STARTMENU_H

#include <QMainWindow>
#include <QTimer>
#include "mainwindow.h"
#include "processor.h"

namespace Ui {
class startmenu;
}

class startmenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit startmenu(QWidget *parent = 0);
    ~startmenu();


    QTimer *time;

public slots:

    void to_game();
    void to_continue();
    void timerslot();

private:
    Ui::startmenu *ui;
};

#endif // STARTMENU_H


