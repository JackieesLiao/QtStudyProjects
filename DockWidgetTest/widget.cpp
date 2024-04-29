#include "widget.h"
#include "ui_widget.h"
#include <QPalette>
#include <QLabel>
#include <QComboBox>
#include <QGridLayout>
#include <QPushButton>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QDockWidget*dock = new QDockWidget("停靠窗口部件测试:Dock Widget",this);
    //设置颜色
    //QPalette pal;
    //pal.setColor(QPalette::Background,Qt::cyan);
    dock->setStyleSheet("background-color:green");
    //dock->setAutoFillBackground(true);
    //dock->setPalette(pal);

    //学历层次
    QLabel*label = new QLabel("学历层次",this);
    QComboBox*combox = new QComboBox();
    combox->addItem("小学");
    combox->addItem("初中");
    combox->addItem("高中");
    combox->addItem("专科");
    combox->addItem("本科");
    combox->addItem("硕士研究生");
    combox->addItem("博士研究生");\
    QPushButton*pBtn1 = new QPushButton("清华大学");
    QPushButton*pBtn2 = new QPushButton("北京大学");
    //栅格布局
    QGridLayout*pGridLay = new QGridLayout();
    pGridLay->addWidget(label,0,0,1,1);
    pGridLay->addWidget(combox,0,0,1,1);
    pGridLay->addWidget(pBtn1,1,0,1,1);
    pGridLay->addWidget(pBtn2,1,1,1,1);
    pGridLay->setHorizontalSpacing(10);
    pGridLay->setVerticalSpacing(10);
    pGridLay->setContentsMargins(10,10,10,10);
    QWidget*widget = new QWidget();
    widget->setLayout(pGridLay);
    dock->setWidget(widget);
    dock->setMaximumSize(300,300);
}

Widget::~Widget()
{
    delete ui;
}

