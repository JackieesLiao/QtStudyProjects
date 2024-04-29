#include "widget.h"
#include <QGridLayout>
#include <QMenu>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //组合框1
    QGroupBox *box1 = new QGroupBox("互相排斥单选按钮组1");
    QRadioButton*radioBtn1 = new QRadioButton("RadioButton1",this);
    QRadioButton*radioBtn2 = new QRadioButton("RadioButton2",this);
    QRadioButton*radioBtn3 = new QRadioButton("RadioButton3",this);
    QVBoxLayout* vbLay = new QVBoxLayout(this);
    vbLay->addWidget(radioBtn1);
    vbLay->addWidget(radioBtn2);
    vbLay->addWidget(radioBtn3);
    box1->setLayout(vbLay);
    //组合框2
    QGroupBox *box2 = new QGroupBox("互相排斥多选按钮组2");
    QCheckBox*checkBox1 = new QCheckBox("checkBox1",this);
    QCheckBox*checkBox2 = new QCheckBox("checkBox2",this);
    QCheckBox*checkBox3 = new QCheckBox("checkBox3",this);
    checkBox2->setTristate(true);
    checkBox3->setTristate(true);
    checkBox1->setChecked(true);
    QVBoxLayout* vbLay2 = new QVBoxLayout(this);
    vbLay2->addWidget(checkBox1);
    vbLay2->addWidget(checkBox2);
    vbLay2->addWidget(checkBox3);
    box2->setLayout(vbLay2);

    //组合框3
    QGroupBox *box3 = new QGroupBox("复选普通按钮组3");
    box3->setCheckable(true);
    QCheckBox*checkBox4 = new QCheckBox("checkBox4",this);
    QPushButton*pBtn4 = new QPushButton("QPushButton4",this);
    QPushButton*pBtn5 = new QPushButton("QPushButton5",this);
    QPushButton*pBtn6 = new QPushButton("QPushButton6",this);
    checkBox4->setChecked(true);
    QVBoxLayout* vbLay3 = new QVBoxLayout(this);
    vbLay3->addWidget(checkBox4);
    vbLay3->addWidget(pBtn4);
    vbLay3->addWidget(pBtn5);
    vbLay3->addWidget(pBtn6);
    box3->setLayout(vbLay3);

    //组合框4
    QGroupBox *box4 = new QGroupBox("综合按钮组4");
    box4->setCheckable(true);
    box4->setChecked(true);
    QCheckBox*checkBox5 = new QCheckBox("checkBox5",this);
    checkBox5->setChecked(true);
    QPushButton*pBtn1 = new QPushButton("PushButton1",this);
    QPushButton*pBtn2 = new QPushButton("PushButton2",this);
    QPushButton*pBtn3 = new QPushButton("PushButton3",this);
    pBtn2->setCheckable(true);
    //pBtn2->setChecked(true);
    //命令按钮添加子菜单
    QMenu*menu = new QMenu(this);
    menu->addAction("green");
    menu->addAction("orange");
    menu->addAction("apple");
    menu->addAction("banana");
    pBtn3->setMenu(menu);//按钮3包含菜单
    QVBoxLayout* vbLay4 = new QVBoxLayout(this);
    vbLay4->addWidget(checkBox5);
    vbLay4->addWidget(pBtn1);
    vbLay4->addWidget(pBtn2);
    vbLay4->addWidget(pBtn3);
    box4->setLayout(vbLay4);
    QGridLayout * gdLay = new QGridLayout(this);
    gdLay->addWidget(box1,0,0,1,1);
    gdLay->addWidget(box2,0,2,1,1);
    gdLay->addWidget(box3,1,0,1,1);
    gdLay->addWidget(box4,1,2,1,1);
}

Widget::~Widget()
{
}

