#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGroupBox>
#include <QRadioButton>
#include <QPushButton>
#include <QCheckBox>
#include <QVBoxLayout> //可以在水平和垂直方向进行排列的控件
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
};
#endif // WIDGET_H
