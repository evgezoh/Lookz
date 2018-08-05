#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //this->setAttribute(Qt::WA_DeleteOnClose);


    //this->setStyleSheet("background-image: url(:/fon.jpg);");

    scene = new QGraphicsScene;
    scene2 = new QGraphicsScene;

    ui->graphicsView->setScene(scene);
    ui->graphicsView_2->setScene(scene2);

    timer = new QTimer;
    timer->start(1);

    timerclock = new QTimer;
    timerclock->start(1000);

    picture = new Pictures;
    picture2 = new Pictures;

    player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/sound.mp3"));
    player->play();

    mistake = new QMediaPlayer;
    mistake->setMedia(QUrl("qrc:/mistake.mp3"));

    qDebug() << QDir::currentPath();

    connect(timer, SIGNAL(timeout()), this, SLOT(timerslot()));
    connect(timerclock, SIGNAL(timeout()), this, SLOT(timerclockslot()));
    connect(ui->to_menu, SIGNAL(clicked()), this, SLOT(to_menu()));

    ui->to_menu->setStyleSheet("background-image: url(:/); "
                               "color: rgb(255, 0, 0); "
                               "background-color: rgba(255, 200, 155, 0); "
                               "border-radius: 5px; "
                               "border: 3px double #ffffff;");

    ui->to_menu->setFont(QFont("Ravie", 12, QFont::Bold, true));


    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    picture->setPicture(Processor::level);
    picture2->setPicture(Processor::level + 10);

    scene->addItem(picture);
    scene2->addItem(picture2);

    ellipse = new QGraphicsEllipseItem[10];

    //QBrush greenBrush(Qt::green);
    //QBrush blueBrush(Qt::blue);
    QPen outlinePen(Qt::red);
    outlinePen.setWidth(3);

    for (int i = 0; i < 5; i++)
    {
        ellipse[i].setRect(0, 0, 50, 50);
        ellipse[i].setVisible(false);
        ellipse[i].setPen(outlinePen);
        scene->addItem(&ellipse[i]);
    }

    for (int i = 5; i < 10; i++)
    {
        ellipse[i].setRect(0, 0, 50, 50);
        ellipse[i].setVisible(false);
        ellipse[i].setPen(outlinePen);
        scene2->addItem(&ellipse[i]);
    }



}

void MainWindow::to_menu()
{
    startmenu *m = new startmenu;
    m->show();

    player->stop();

    Processor::time = 100;

    delete this;
}

void MainWindow::mousePressEvent(QMouseEvent * event)
{
    if(event->button() == Qt::LeftButton)
        qDebug() << "left mouse click ";

    if(event->button() == Qt::RightButton)
        qDebug() << "right mouse click ";

    qDebug() << event->pos();
    qDebug() << ((double)event->pos().x() - ui->graphicsView->pos().x()) / picture->getWidth();

    qDebug() << ((double)event->pos().y() - ui->graphicsView->pos().y()) / picture->getHeight();

    if (clickgreen(event->pos().x(), event->pos().y()))
    {
        qDebug() << "Green";
        Processor::green++;
    }
    else
    {
        qDebug() << "Red";
        Processor::red++;
        mistake->play();
    }


    qDebug() << Processor::green << " " << Processor::red;

    if (Processor::green == 5)
    {
        Processor::green = 0;
        Processor::red = 0;
        Processor::level++;
        Processor::newLevel = true;
        //setPoints();
        Processor::time = 100;

        for (int i = 0; i < 10; i++)
        {
            ellipse[i].setX(-100);
            ellipse[i].setY(-100);
            ellipse[i].setVisible(false);
        }
    }
    if (Processor::red == 3)
    {
        Processor::green = 0;
        Processor::red = 0;
        //setPoints();

        to_menu();
    }

    setPoints();
}

void MainWindow::setPoints()
{
    switch (Processor::green)
    {
        case 1: ui->label_3->setStyleSheet("background-image: url(:/); border: 3px double #cc5555; background-color: rgba(0, 255, 0, 155);"); break;
        case 2: ui->label_4->setStyleSheet("background-image: url(:/); border: 3px double #cc5555; background-color: rgba(0, 255, 0, 155);"); break;
        case 3: ui->label_5->setStyleSheet("background-image: url(:/); border: 3px double #cc5555; background-color: rgba(0, 255, 0, 155);"); break;
        case 4: ui->label_6->setStyleSheet("background-image: url(:/); border: 3px double #cc5555; background-color: rgba(0, 255, 0, 155);"); break;
        case 5: ui->label_7->setStyleSheet("background-image: url(:/); border: 3px double #cc5555; background-color: rgba(0, 255, 0, 155);"); break;
    case 0:
        ui->label_3->setStyleSheet("background-image: url(:/); border: 3px double #cc5555; background-color: rgba(0, 255, 0, 50);");
        ui->label_4->setStyleSheet("background-image: url(:/); border: 3px double #cc5555; background-color: rgba(0, 255, 0, 50);");
        ui->label_5->setStyleSheet("background-image: url(:/); border: 3px double #cc5555; background-color: rgba(0, 255, 0, 50);");
        ui->label_6->setStyleSheet("background-image: url(:/); border: 3px double #cc5555; background-color: rgba(0, 255, 0, 50);");
        ui->label_7->setStyleSheet("background-image: url(:/); border: 3px double #cc5555; background-color: rgba(0, 255, 0, 50);");
        break;
    }

    switch (Processor::red)
    {
        case 1: ui->label_2->setStyleSheet("background-image: url(:/); border: 3px double #55cc55; background-color: rgba(255, 0, 0, 155)"); break;
        case 2: ui->label_8->setStyleSheet("background-image: url(:/); border: 3px double #55cc55; background-color: rgba(255, 0, 0, 155)"); break;
        case 3: ui->label_9->setStyleSheet("background-image: url(:/); border: 3px double #55cc55; background-color: rgba(255, 0, 0, 155)"); break;
    case 0:
        ui->label_2->setStyleSheet("background-image: url(:/); border: 3px double #55cc55; background-color: rgba(255, 0, 0, 50)");
        ui->label_8->setStyleSheet("background-image: url(:/); border: 3px double #55cc55; background-color: rgba(255, 0, 0, 50)");
        ui->label_9->setStyleSheet("background-image: url(:/); border: 3px double #55cc55; background-color: rgba(255, 0, 0, 50)");
        break;
    }
}

bool MainWindow::clickgreen(int x, int y)
{
    for (int i = 0; i < picture->qVec[Processor::level - 1].size(); i++)
    {
        if (((fabs((double)(x - ui->graphicsView->pos().x()) / picture->getWidth() - picture->qVec[Processor::level - 1][i].x() / 100.0) <= 0.03) &&
             (fabs((double)(y - ui->graphicsView->pos().y()) / picture->getHeight() - picture->qVec[Processor::level - 1][i].y() / 100.0) <= 0.03 )) ||
            ((fabs((double)(x - ui->graphicsView_2->pos().x()) / picture2->getWidth() - picture->qVec[Processor::level - 1][i].x() / 100.0) <= 0.03 ) &&
             (fabs((double)(y - ui->graphicsView_2->pos().y()) / picture2->getHeight() - picture->qVec[Processor::level - 1][i].y() / 100.0) <= 0.03 )))
        {
            ellipse[Processor::green].setX((picture->qVec[Processor::level - 1][i].x() / 100.0) * picture->getWidth() - 20);
            ellipse[Processor::green].setY((picture->qVec[Processor::level - 1][i].y() / 100.0) * picture->getHeight() - 20);

            ellipse[Processor::green + 5].setX((picture->qVec[Processor::level - 1][i].x() / 100.0) * picture2->getWidth() - 20);
            ellipse[Processor::green + 5].setY((picture->qVec[Processor::level - 1][i].y() / 100.0) * picture2->getHeight() - 20);

            ellipse[Processor::green].setVisible(true);
            ellipse[Processor::green + 5].setVisible(true);

            scene->update();
            scene2->update();

            picture->qVec[Processor::level - 1][i].setX(-1000);
            picture->qVec[Processor::level - 1][i].setY(-1000);

            return true;
        }
    }

    return false;

}

void MainWindow::timerclockslot()
{
    ui->label->setText(QString::number(Processor::time--)); ////////////////////////

    if (!Processor::time)
    {
        to_menu();
    }
}

void MainWindow::timerslot()
{
    if (Processor::newLevel)
    {
        picture->setPicture(Processor::level);
        picture2->setPicture(Processor::level + 10);

        scene->update();
        //scene->addItem(picture);
        scene2->update();
        //scene2->addItem(picture2);

        Processor::newLevel = false;
    }

    scene->setSceneRect(0, 0, ui->graphicsView->width() - 2, ui->graphicsView->height() - 2);
    scene2->setSceneRect(0, 0, ui->graphicsView_2->width() - 2, ui->graphicsView_2->height() - 2);
    picture->setWidth(scene->width());
    picture2->setWidth(scene2->width());
    picture->setHeight(scene->height());
    picture2->setHeight(scene2->height());
}

MainWindow::~MainWindow()
{
    delete timer;

    delete picture;
    delete picture2;

    delete player;

    delete scene;
    delete scene2;

    delete ui;
}















