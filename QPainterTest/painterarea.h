#ifndef PAINTERAREA_H
#define PAINTERAREA_H
//实现绘图
#include <QWidget>
#include <QPen>   //QPen 是基本的图形对象 ，绘制直线，曲线，多边形等形状
#include <QBrush> //QBrush 画刷是基本的图形对象，主要用于填充比如矩形于多边形等
#include <QPainter>
class PainterArea : public QWidget
{
    Q_OBJECT
public:
    explicit PainterArea(QWidget *parent = nullptr);
    enum Shape{
        Line,    //直线
        rectangle//矩形
    };
    void setShape(Shape);//绘制形状
    void setPen(QPen);
    void setBrush(QBrush);
    void paintEvent(QPaintEvent *event) override;//重绘事件
    void setfillrule(Qt::FillRule);//填充规则
private:
    Shape shape_;
    QPen pen_;
    QBrush brush_;
    Qt::FillRule fillrule_;
};

#endif // PAINTERAREA_H
