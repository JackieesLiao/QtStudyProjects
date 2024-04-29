#include "painterarea.h"

PainterArea::PainterArea(QWidget *parent)
    : QWidget{parent}
{
    setPalette(QPalette(Qt::green));//调色板来改变背景颜色
    setAutoFillBackground(true);    //Qt窗口是否需要绘制背景
    setMinimumSize(410,410);        //设置最小尺寸

}

void PainterArea::setShape(Shape shape)
{
    shape_ = shape;
    update();
}

void PainterArea::setPen(QPen pen)
{
    pen_ = pen;
    update();
}

void PainterArea::setBrush(QBrush brush)
{
    brush_ = brush;
    update();
}
//重绘事件
void PainterArea::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(pen_);
    painter.setBrush(brush_);

    QRect rect(55,110,290,280);
    switch (shape_) {
    case Line://画直线
        painter.drawLine(rect.topLeft(),rect.bottomRight());
        break;
    case rectangle:
        painter.drawRect(rect);
        break;
    default:
        break;
    }
}
//填充规则
void PainterArea::setfillrule(Qt::FillRule rule)
{
    fillrule_ = rule;
    update();//重新绘制区域窗体
}
