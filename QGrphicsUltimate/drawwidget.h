#ifndef DRAWWIDGET_H
#define DRAWWIDGET_H

#include <QWidget>
#include <QColor>
#include <QtGui>
#include <QMouseEvent> //鼠标事件相关
#include <QPaintEvent> //绘制事件
#include <QResizeEvent> //实时获取窗口操作等大小
#include <QPixmap>      //显示图像
#include <QPainter>
#include <QPalette>
#include <QPen>
class DrawWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DrawWidget(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent*) override;
    void mouseMoveEvent(QMouseEvent*) override;
    void paintEvent(QPaintEvent*) override;
    void resizeEvent(QResizeEvent* ) override;

private:
    QPixmap * pix;
    QPoint startPoint;//绘制起始点
    QPoint endPoint;  //绘制终止点
    QColor color;
    int style_,width_;
public slots:
    void setStyle(int);   //设置线条风格
    void setWidth(int);   //设置线条宽度
    void setColor(QColor);//设置线颜色
    void clearFunc();     //清除函数
signals:
};

#endif // DRAWWIDGET_H
