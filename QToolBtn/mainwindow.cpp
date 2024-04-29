#include "mainwindow.h"
#include <QStyle>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //3.设置窗口运行位置
    this->setGeometry(300,160,500,300);
    //4.将QToolBtn对象进行实例化
    tbar1 = new QToolBar(this);
    tbar1->setGeometry(20,20,200,50);
    //5.将QStyle对象进行实例化，主要设置风格
    QStyle *style = QApplication::style();
    QIcon icon = style->standardIcon(QStyle::SP_TitleBarContextHelpButton);
    //6.将QToolBtn对象进行实例化
    tbtn = new QToolButton(this);
    tbtn->setIcon(icon);
    tbtn->setText("系统帮助提示");//设置将要显示文本
    //调用setToolButtonStyle函数设置toolbutton样式，设置文本在图标下方
    tbtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    //将tbtn加入tbar中
    tbar1->addWidget(tbtn);
}

MainWindow::~MainWindow()
{
}

