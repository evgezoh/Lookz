#include "mainwindow.h"
#include "startmenu.h"
#include "processor.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    startmenu *m = new startmenu;
    m->show();

    return a.exec();
}

///




