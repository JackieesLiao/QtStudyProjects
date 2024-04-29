#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    /*网格布局的使用*/
    pBtn1 = new QPushButton(this);
    pBtn1->setText("第一区：顶部菜单栏选项");
    pBtn1->setFixedHeight(40);//设置固定大小高度
    pBtn1->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    pBtn2 = new QPushButton(this);
    pBtn2->setText("第二区：侧边栏选项");
    pBtn2->setFixedWidth(200);//设置固定大小宽度
    pBtn2->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    pBtn3 = new QPushButton(this);
    pBtn3->setText("第三区：底部选项");
    pBtn3->setFixedHeight(40);//设置固定大小高度
    pBtn3->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    pBtn4 = new QPushButton(this);
    pBtn4->setText("第四区：子窗体选项");
    pBtn4->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    pGirdLay = new QGridLayout(this);
    pGirdLay->setContentsMargins(0,0,0,0);//设置与父布局之间的间隔
    //pGirdLay->setMargin(30);
    pGirdLay->setSpacing(40);
    //pGirdLay->setSpacing(0);
    //addwidget(参数1，参数2，参数3 ...);
    //1.要插入的子布局对象
    //2.插入的开始行
    //3.插入的开始列
    //4.占用的行数
    //5.占用的列数
    //6.指定的对齐方式
    pGirdLay->addWidget(pBtn1,0,1);//将控件加入布局中
    pGirdLay->addWidget(pBtn2,0,0,3,1);
    pGirdLay->addWidget(pBtn3,2,1);
    pGirdLay->addWidget(pBtn4,1,1,1,1);
    setLayout(pGirdLay);
}

Widget::~Widget()
{
}

