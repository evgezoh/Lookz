#include "menu.h"
#include "ui_menu.h"

menu::menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::menu)
{//

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

void menu::timerslot()
{
    if (this->width() > this->height())
    {
        ui->game->setStyleSheet("background-image: url(:/); border-radius: 15px; border: 7px double #aa55cc; color: red");
    }
    else
    {
        ui->game->setStyleSheet("background-image: url(:/); border-radius: 15px; border: 7px double #aa55cc; color: green");
    }
}

void menu::to_continue()
{
    MainWindow *w = new MainWindow;
    w->show();

    delete this;
}

void menu::to_game()
{
    MainWindow *w = new MainWindow;
    w->show();

    delete this;
}

menu::~menu()
{
    delete ui;
}

































