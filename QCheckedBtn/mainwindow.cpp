#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(400,300,500,300);
    this->setStyleSheet("QWidget {background-color:rgba(255,100,0,100%);}");
    //实例化操作
    checkBox = new QCheckBox(this);
    checkBox->setGeometry(30,50,250,50);
    checkBox->setCheckState(Qt::Checked);
    checkBox->setText("初始状态为：Checked状态");//初始化三态复选框状态
    checkBox->setTristate();//开启三态状态,必须开启，否则只有Checked和Unchecked
    connect(checkBox,&QCheckBox::stateChanged,this,&MainWindow::SlotCheckBoxState);

}

void MainWindow::SlotCheckBoxState(int isState)
{
    //判断checkBox的状态
    switch (isState) {
    case Qt::Checked://选中状态
        checkBox->setText("选中状态OK");
        break;
    case Qt::Unchecked://未来选中状态
        checkBox->setText("未选中状态NO");
        break;
    case Qt::PartiallyChecked://半选中状态
        checkBox->setText("半选中状态OK");
        break;
    default:
        break;
    }
}
MainWindow::~MainWindow()
{
}
