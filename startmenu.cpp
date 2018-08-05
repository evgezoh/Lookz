#include "startmenu.h"
#include "ui_startmenu.h"

startmenu::startmenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::startmenu)
{
    ui->setupUi(this);

    //this->setAttribute(Qt::WA_DeleteOnClose);

    time = new QTimer;
    time->start(1000);

    //this->setStyleSheet("background-image: url(:/menu.jpg);");

    connect(ui->game, SIGNAL(clicked()), this, SLOT(to_game()));
    connect(ui->end, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->continue_2, SIGNAL(clicked()), this, SLOT(to_continue()));

    connect(time, SIGNAL(timeout()), this, SLOT(timerslot()));
}

void startmenu::timerslot()
{
    if (this->width() > this->height())
    {
        ui->game->setStyleSheet("background-image: url(:/); border-radius: 15px; border: 7px double #aa55cc; color: red");
        Processor::b_orientation = false;
    }
    else
    {
        ui->game->setStyleSheet("background-image: url(:/); border-radius: 15px; border: 7px double #aa55cc; color: green");
        Processor::b_orientation = true;
    }
}

void startmenu::to_continue()
{
    MainWindow *w = new MainWindow;
    w->show();

    delete this;
}

void startmenu::to_game()
{
    Processor::level = 1;

    MainWindow *w = new MainWindow;
    w->show();

    delete this;
}

startmenu::~startmenu()
{
    delete ui;
}
















