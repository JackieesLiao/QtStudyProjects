#ifndef PIXITEM_H
#define PIXITEM_H

#include <QGraphicsItem>//图元类
#include <QPixmap>
#include <QPainter>
class PixItem : public QGraphicsItem
{
public:
    PixItem(QPixmap * pixmap);
private:
    QPixmap pix;
public:

    QRectF boundingRect() const override;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

};

#endif // PIXITEM_H
