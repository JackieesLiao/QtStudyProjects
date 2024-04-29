#include "widget.h"
#include <QDesktopServices>//引入桌面服务
#include <QUrl> //引入url
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setGeometry(400,300,500,300);
    this->setStyleSheet("QWidget {background-color:rgba(255,100,0,100%);}");
    clb = new QCommandLinkButton("testClb","clicked testClb",this);
    clb->setGeometry(50,100,250,60);
    connect(clb,&QCommandLinkButton::clicked,this,&Widget::SlotClbClicked);
}

Widget::~Widget()
{
}

void Widget::SlotClbClicked()
{
    //调用系统服务打开操作
    QDesktopServices::openUrl(QUrl("www.google.com"));

}

