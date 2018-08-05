#ifndef MWINDOW_H
#define MWINDOW_H

#include <QWidget>
#include "mainwindow.h"
#include "menu.h"
#include "processor.h"
#include <QTimer>

namespace Ui {
class MWindow;
}

class MWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MWindow(QWidget *parent = 0);
    ~MWindow();

    QTimer *time;
    MainWindow *w;
    menu *m;

private:
    Ui::MWindow *ui;

public slots:

    void timerslot();
};

#endif // MWINDOW_H
