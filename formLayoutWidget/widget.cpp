#include "widget.h"
#include <QFormLayout>
#include <QLineEdit>
#include <QLabel>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(250,200);

    QFormLayout*qLay = new QFormLayout(this);//创建表单布局
    QLineEdit * lineEdit1 = new QLineEdit(this);//输入学号
    QLineEdit * lineEdit2 = new QLineEdit(this);//输入姓名
    QLineEdit * lineEdit3 = new QLineEdit(this);//输入学校
    qLay->addRow("学校",lineEdit1);
    qLay->addRow("姓名",lineEdit2);
    qLay->addRow("学号",lineEdit3);
    qLay->setSpacing(0);
    //WrapAllRows将标签显示在单行编辑框上
    //qLay->setRowWrapPolicy(QFormLayout::WrapAllRows);
    //当标签和单选编辑框，将标签显示在同一行
    qLay->setRowWrapPolicy(QFormLayout::WrapLongRows);
    qLay->setLabelAlignment(Qt::AlignLeft);    //标签左对齐
    setWindowTitle("表单布局测试案例");
}

Widget::~Widget()
{
}

