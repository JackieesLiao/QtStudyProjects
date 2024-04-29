#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>      //标签
#include <QPushButton> //按钮
#include <QGridLayout> //网格布局
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QGridLayout * pGirdLay;
    QPushButton * pBtn1;
    QPushButton * pBtn2;
    QPushButton * pBtn3;
    QPushButton * pBtn4;
};
#endif // WIDGET_H
