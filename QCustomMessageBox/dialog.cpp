#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    this->resize(270,100);
    pGridLay = new QGridLayout(this);
    labelMsg = new QLabel("自定义消息框");
    msgBtn = new QPushButton("测试操作");
    labelDisPlayMsg = new QLabel("未测试状态");

    pGridLay->addWidget(labelMsg,0,0);
    pGridLay->addWidget(msgBtn,0,1);
    pGridLay->addWidget(labelDisPlayMsg,1,0,1,1);
    connect(msgBtn,&QPushButton::clicked,this,&Dialog::SlotCustomMsg);
}

Dialog::~Dialog()
{
}

void Dialog::SlotCustomMsg()
{
    QMessageBox * cMsgBox = new QMessageBox;
    cMsgBox->setWindowTitle("测试消息框");
    //添加按钮
    QPushButton * yes = cMsgBox->addButton("YES",QMessageBox::ActionRole);
    QPushButton * no = cMsgBox->addButton("NO",QMessageBox::ActionRole);
    //添加图标
    cMsgBox->setIconPixmap(QPixmap(":/new/prefix1/icon/wallhaven-zyr7jw.jpg"));
    cMsgBox->exec();
    //判断用户是否点击按钮yes no
    if(cMsgBox->clickedButton() == yes){
        labelDisPlayMsg->setText("用户点击按钮YES");
    }else if(cMsgBox->clickedButton() == no){
        labelDisPlayMsg->setText("用户点击按钮NO");
    }
}

