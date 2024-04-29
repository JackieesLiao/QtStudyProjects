#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setGeometry(300,160,500,300);
    this->setStyleSheet("QWidget {background-color:rgba(255,0,0,100%);}");
    //将QRadioBtn的对象进行实例化
    radioBtn1 = new QRadioButton(this);
    radioBtn2 = new QRadioButton(this);
    //设置两个对象位置
    radioBtn1->setGeometry(20,20,150,40);
    radioBtn2->setGeometry(20,80,150,40);
    //设置两个单选按钮文本
    radioBtn1->setText("选择按钮1");
    radioBtn2->setText("选择按钮2");
    //设置命令按钮默认值check
    radioBtn1->setChecked(true);
    radioBtn2->setChecked(false);
}

Widget::~Widget()
{
}

