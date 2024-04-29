#include "stackeddlg.h"
#include <QHBoxLayout>
StackedDlg::StackedDlg(QWidget *parent)
    : QDialog(parent)
{
    this->setWindowTitle("堆栈窗体测试");
    qList = new QListWidget(this);
    qList->insertItem(0,"linux1");
    qList->insertItem(1,"linux2");
    qList->insertItem(2,"linux3");
    qList->insertItem(3,"linux4");
    qList->insertItem(4,"linux5");

    label1 = new QLabel("linux1 Qt");
    label2 = new QLabel("linux2 Qt");
    label3 = new QLabel("linux3 Qt");
    label4 = new QLabel("linux4 Qt");
    label5 = new QLabel("linux5 Qt");
    //QStackedWidget 控件相当于一个窗口，提供一个空间专门存放一些控件，并且每次只有一个控件可见，被设置为当前的控件
    stacks = new QStackedWidget(this);
    stacks->addWidget(label1);
    stacks->addWidget(label2);
    stacks->addWidget(label3);
    stacks->addWidget(label4);
    stacks->addWidget(label5);
    QHBoxLayout * mLayout = new QHBoxLayout(this);
    mLayout->setSpacing(20);
    mLayout->addWidget(qList);
    mLayout->addWidget(stacks,0,Qt::AlignCenter);
    mLayout->setStretchFactor(qList,5);
    mLayout->setStretchFactor(stacks,5);
}

StackedDlg::~StackedDlg()
{
}

