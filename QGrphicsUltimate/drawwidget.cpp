#include "drawwidget.h"

DrawWidget::DrawWidget(QWidget *parent)
    : QWidget{parent}
{
    setAutoFillBackground(true);
    setPalette(QPalette(Qt::white));
    pix = new QPixmap(size());
    pix->fill(Qt::white);
    //设置绘制区窗口大小
    setMinimumSize(600,400);
}

void DrawWidget::mousePressEvent(QMouseEvent * e)
{
    startPoint = e->pos();
}

void DrawWidget::mouseMoveEvent(QMouseEvent * e)
{
    QPainter * painter = new QPainter;
    QPen pen;
    pen.setStyle((Qt::PenStyle)style_);
    pen.setWidth(width_);
    pen.setColor(color);

    painter->begin(pix);  //开始绘制
    painter->setPen(pen); //设置画笔
    painter->drawLine(startPoint,e->pos());//开始绘制，起点是 startPoint，终点是当前鼠标的位置 e->pos()。
    painter->end();      //结束绘制

    //绘制完成之后记录point位置
    startPoint = e->pos();
    update();
}

void DrawWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(QPoint(0,0),*pix);

}

void DrawWidget::resizeEvent(QResizeEvent * event)
{
    if(height()>pix->height() || width()>pix->width()){
        //则创建一个新的 QPixmap 对象（newPix），
        //其大小与部件的新大小相同，并用白色填充。
        QPixmap * newPix = new QPixmap(size());
        newPix->fill(Qt::white);
        //创建一个 QPainter 对象（ps），用于在新的 QPixmap 上进行绘制
        QPainter ps(newPix);
        //将之前的 QPixmap 对象（pix）绘制到新的 QPixmap 上，以保留之前的绘制内容。
        ps.drawPixmap(QPoint(0,0),*pix);
        //将新创建的 QPixmap 对象（newPix）赋值给 pix，以便在下一次绘制时使用。
        pix = newPix;
    }
    //确保父类的 resizeEvent 函数也能得到调用
    QWidget::resizeEvent(event);
}

void DrawWidget::setStyle(int style)
{
    style_ = style;
}

void DrawWidget::setWidth(int width)
{
    width_ = width;
}

void DrawWidget::setColor(QColor c)
{
    color = c;
}

void DrawWidget::clearFunc()
{
    QPixmap *cPix = new QPixmap(size());
    cPix->fill(Qt::white);
    pix = cPix;
    update();
}
