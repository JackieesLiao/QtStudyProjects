#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //设置窗口运行的位置
    this->setGeometry(300,160,500,300);
    //实例化两个命令按钮
    pBtn1 = new QPushButton("命令按钮1",this);
    pBtn2 = new QPushButton("命令按钮2",this);

    //设置两个QPushBtn的对象坐标位置
    pBtn1->setGeometry(20,20,150,50);
    pBtn1->setGeometry(20,90,150,50);
    connect(pBtn1,&QPushButton::clicked,this,&Widget::SlotPushBtn1Clicked);
    connect(pBtn2,&QPushButton::clicked,this,&Widget::SlotPushBtn2Clicked);
}

Widget::~Widget()
{
}

void Widget::SlotPushBtn1Clicked()
{
    this->setStyleSheet("QWidget{background-color:rgba(255,255,0,100%);}");
}

void Widget::SlotPushBtn2Clicked()
{
    this->setStyleSheet("QWidget{background-color:rgba(255,0,0,100%);}");
}

