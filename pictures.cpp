#include "pictures.h"
#include "processor.h"


Pictures::Pictures()
{
     pWidth = 100;
     pHeight = 100;

     qvec.push_back(QPoint(100, 100));
     qvec.push_back(QPoint(20, 60));
     qvec.push_back(QPoint(100, 100));
     qvec.push_back(QPoint(100, 100));
     qvec.push_back(QPoint(100, 100));
     qvec.push_back(QPoint(100, 100));
     qvec.push_back(QPoint(100, 100));
     qvec.push_back(QPoint(100, 100));
     qvec.push_back(QPoint(100, 100));
     qvec.push_back(QPoint(100, 100));

     QVector <QPoint> q;
     q.push_back(QPoint(20, 60));
     q.push_back(QPoint(90, 30));
     q.push_back(QPoint(79, 29));
     q.push_back(QPoint(90, 43));
     q.push_back(QPoint(4, 93));
     qVec.push_back(q);

     q.clear();
     q.push_back(QPoint(48, 80));
     q.push_back(QPoint(42, 11));
     q.push_back(QPoint(92, 79));
     q.push_back(QPoint(22, 19));
     q.push_back(QPoint(89, 44));
     qVec.push_back(q);

     q.clear();
     q.push_back(QPoint(28, 91));
     q.push_back(QPoint(54, 15));
     q.push_back(QPoint(90, 12));
     q.push_back(QPoint(4, 50));
     q.push_back(QPoint(9, 24));
     qVec.push_back(q);

     q.clear();
     q.push_back(QPoint(75, 47));
     q.push_back(QPoint(78, 19));
     q.push_back(QPoint(98, 95));
     q.push_back(QPoint(66, 76));
     q.push_back(QPoint(1, 17));
     qVec.push_back(q);

     q.clear();
     q.push_back(QPoint(2, 49));
     q.push_back(QPoint(55, 52));
     q.push_back(QPoint(41, 89));
     q.push_back(QPoint(85, 66));
     q.push_back(QPoint(89, 2));
     qVec.push_back(q);
}

QRectF Pictures::boundingRect() const
{
         return QRectF(0,0,0,0);
}

void Pictures::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
        //painter->drawEllipse(100,100,50,50);
        painter->drawPixmap(0, 0, pWidth, pHeight, *pixmap);



        //update();
        Q_UNUSED(option);
        Q_UNUSED(widget);
}

void Pictures::setPicture(int level)
{
    switch(level)
    {
        case 1: if (Processor::newLevel) delete pixmap; pixmap = new QPixmap(":gorod_2.jpg"); break; // память
        case 2: if (Processor::newLevel) delete pixmap; pixmap = new QPixmap(":priroda_2.jpg"); break;
        case 3: if (Processor::newLevel) delete pixmap; pixmap = new QPixmap(":skala_2.jpg"); break;
        case 4: if (Processor::newLevel) delete pixmap; pixmap = new QPixmap(":plane_2.jpg"); break;
        case 5: if (Processor::newLevel) delete pixmap; pixmap = new QPixmap(":sea_2.jpg"); break;
        case 6: if (Processor::newLevel) delete pixmap; pixmap = new QPixmap(":israel_2.jpg"); break;
//        case 7: if (Processor::newLevel) delete pixmap; pixmap = new QPixmap(":monkey.jpg"); break;
//        case 8: if (Processor::newLevel) delete pixmap; pixmap = new QPixmap(":priroda.jpg"); break;
//        case 9: if (Processor::newLevel) delete pixmap; pixmap = new QPixmap(":skala.jpg"); break;
//        case 10: if (Processor::newLevel) delete pixmap; pixmap = new QPixmap(":wolf.jpg"); break;
        case 11: if (Processor::newLevel) delete pixmap; pixmap = new QPixmap(":gorod_1.jpg"); break;
        case 12: if (Processor::newLevel) delete pixmap; pixmap = new QPixmap(":priroda_1.jpg"); break;
        case 13: if (Processor::newLevel) delete pixmap; pixmap = new QPixmap(":skala_1.jpg"); break;
        case 14: if (Processor::newLevel) delete pixmap; pixmap = new QPixmap(":plane_1.jpg"); break;
        case 15: if (Processor::newLevel) delete pixmap; pixmap = new QPixmap(":sea_1.jpg"); break;
        case 16: if (Processor::newLevel) delete pixmap; pixmap = new QPixmap(":israel_1.jpg"); break;
    }
}

void Pictures::setWidth(int w)
{
    pWidth = w;
    //update();
}

void Pictures::setHeight(int h)
{
    pHeight = h;
    //update();
}

int Pictures::getWidth()
{
    return pWidth;
}

int Pictures::getHeight()
{
    return pHeight;
}

Pictures::~Pictures()
{

}
