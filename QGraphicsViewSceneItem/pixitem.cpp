#include "pixitem.h"

PixItem::PixItem(QPixmap * pixmap)
{
    pix = *pixmap;
}
///只刷新固定区域, 返回调整成实际物体所在位置的包含区域
QRectF PixItem::boundingRect() const
{
    return QRectF(-2-pix.width()/2,-2-pix.height()/2,pix.width() + 4,pix.height() + 4);
}
///绘制操作
void PixItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-pix.width()/2,-pix.height()/2,pix);
}
