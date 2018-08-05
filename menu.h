#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QTimer>
#include "mainwindow.h"
#include "processor.h"

namespace Ui {
class menu;
}

class menu : public QWidget
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = 0);
    ~menu();

    QTimer *time;

public slots:

    void to_game();
    void to_continue();
    void timerslot();

private:
    Ui::menu *ui;
};

#endif // MENU_H
//
