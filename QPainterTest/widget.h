#ifndef WIDGET_H
#define WIDGET_H

#include "painterarea.h"
#include <QWidget>
#include <QPainter>
#include <QComboBox>
#include <QColorDialog>
#include <QLabel>
#include <QGridLayout>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    PainterArea * labelShapeArea;
    QLabel * labelShape;
    QComboBox * comboxShape;
    QGridLayout * pGridLay;
private slots:
    void SlotDisplayShape(int);//根据combox里的值去绘制PiantArea区域里的形状
};
#endif // WIDGET_H
