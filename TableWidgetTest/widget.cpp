#include "widget.h"
#include <QLabel>
#include <QMessageBox>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle("标签小部件控件测试");
    this->setGeometry(300,200,600,400);

    table_widget = new QTabWidget(this);
    table_widget->setGeometry(20,10,560,360);
    table_widget->show();
    bool m_showtabwidget1 = true;
    bool m_showtabwidget2 = false;
//    bool m_showtabwidget3 = false;
//    bool m_showtabwidget4 = false;
    if(m_showtabwidget1){
        QWidget*qwidget1 = new QWidget();
        table_widget->addTab(qwidget1,"进程");
        QGridLayout *pGridLay = new QGridLayout();
        QLabel * label = new QLabel("请选择文件及文件夹");
        QLineEdit *lineEdit = new QLineEdit();
        QPushButton*pBtn = new QPushButton("消息框");
        connect(pBtn,&QPushButton::clicked,this,&Widget::SlotMsgCommitCliecked);
        pGridLay->addWidget(label,0,0);
        pGridLay->addWidget(lineEdit,0,1);
        pGridLay->addWidget(pBtn,0,2);
        qwidget1->setLayout(pGridLay);
    }
    if(m_showtabwidget2){
        QWidget*qwidget2 = new QWidget();
        table_widget->addTab(qwidget2,"性能");
    }
}

Widget::~Widget()
{

}

void Widget::SlotMsgCommitCliecked()
{
    QMessageBox::information(nullptr,"testing","QMessageBox:命令按钮测试成功",QMessageBox::Ok);
}

