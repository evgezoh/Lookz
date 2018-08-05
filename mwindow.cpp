#include "mwindow.h"
#include "ui_mwindow.h"

MWindow::MWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MWindow)
{
    ui->setupUi(this);

    time = new QTimer;
    time->start();

    connect(time, SIGNAL(timeout()), this, SLOT(timerslot()));
}

void MWindow::timerslot()
{
    if (Processor::Menu)
    {
        if (Processor::inGame)
        {
            //delete w;
        }
        Processor::Menu = false;
        m = new menu;
        m->show();
    }
    else
    {
       if (Processor::Game)
       {
           if (Processor::inGame)
           {
               //delete m;
           }
           Processor::Game = false;
           w = new MainWindow;
           w->show();
       }
    }
    Processor::inGame = true;
}

MWindow::~MWindow()
{
    delete ui;
}
