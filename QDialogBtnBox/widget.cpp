#include "widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setGeometry(400,300,500,300);
    btnBox = new QDialogButtonBox(this);
    btnBox->setGeometry(300,200,200,30);
    btnBox->addButton(QDialogButtonBox::Cancel);
    btnBox->button(QDialogButtonBox::Cancel)->setText("取消");
    pBtn = new QPushButton("自定义",this);
    //将pBtn添加到btnBox，
    btnBox->addButton(pBtn,QDialogButtonBox::ActionRole);
    connect(btnBox,&QDialogButtonBox::clicked,this,
            &Widget::btnBoxClicked);
}

Widget::~Widget()
{
}

void Widget::btnBoxClicked(QAbstractButton *Btn)
{
    if(Btn == btnBox->button(QDialogButtonBox::Cancel)){
        qDebug() << "你已经点击取消按钮";
    }else if(Btn == pBtn){
        qDebug() << "你已经点击自定义按钮";
    }
}

