#ifndef PICTURES_H
#define PICTURES_H

#include <QGraphicsItem>
#include <QPainter>
#include <QStyleOptionGraphicsItem>

class Pointss
{
public:

    QVector <QPoint> P;

    Pointss(QPoint P1, QPoint P2, QPoint P3, QPoint P4, QPoint P5)
    {
            P.push_back(P1);
            P.push_back(P2);
            P.push_back(P3);
            P.push_back(P4);
            P.push_back(P5);
    }
};

struct Poin
{
    QVector <QPoint> P;
};

class Pictures : public QGraphicsItem
{
private:

    int pWidth;
    int pHeight;

public:

     Pictures();
     ~Pictures();

     QPixmap *pixmap;
     QVector <QPoint> qvec;

     QVector <QVector<QPoint>> qVec;

     void setWidth(int w);
     void setHeight(int h);

     int getWidth();
     int getHeight();

     void setPicture(int level = 1);

     QRectF boundingRect() const;

     void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // PICTURES_H
