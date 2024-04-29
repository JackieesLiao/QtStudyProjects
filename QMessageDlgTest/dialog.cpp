#include "dialog.h"
#include <qmessagebox.h>
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    pGridLay = new QGridLayout(this);
    disLabel = new QLabel("请你选择一个消息框");
    questionBtn = new QPushButton("questionBtn");
    infoBtn = new QPushButton("infoBtn");
    warningBtn = new QPushButton("warningBtn");
    criticalBtn = new QPushButton("criticalBtn");
    aboutBtn = new QPushButton("aboutBtn");
    aboutQtBtn= new QPushButton("aboutQtBtn");

    pGridLay->addWidget(disLabel,0,0,1,2);
    pGridLay->addWidget(questionBtn,1,0);
    pGridLay->addWidget(infoBtn,1,1);
    pGridLay->addWidget(warningBtn,2,0);
    pGridLay->addWidget(criticalBtn,2,1);
    pGridLay->addWidget(aboutBtn,3,0);
    pGridLay->addWidget(aboutQtBtn,3,1);
    connect(questionBtn,&QPushButton::clicked,this,&Dialog::SlotQuestionBtn);
    connect(infoBtn,&QPushButton::clicked,this,&Dialog::SlotInfoBtn);
    connect(warningBtn,&QPushButton::clicked,this,&Dialog::SlotWarningBtn);
    connect(criticalBtn,&QPushButton::clicked,this,&Dialog::SlotCriticalBtn);
    connect(aboutBtn,&QPushButton::clicked,this,&Dialog::SlotAboutBtn);
    connect(aboutQtBtn,&QPushButton::clicked,this,&Dialog::SlotAboutQtBtn);
}

Dialog::~Dialog()
{
}

void Dialog::SlotQuestionBtn()
{
    disLabel->setText("Question Message Box");
    switch (QMessageBox::question(this,"Question消息框","你是否想退出程序应用,请选择?",
 QMessageBox::Ok | QMessageBox::Cancel ,QMessageBox::Ok)) {
    case QMessageBox::Ok:
        disLabel->setText("你选择QuestionMSG中OK按钮");
        break;
    case QMessageBox::Cancel:
        disLabel->setText("你选择QuestionMSG中Cancel按钮");
        break;
    default:
        break;
    }
}

void Dialog::SlotInfoBtn()
{
    disLabel->setText("infomation Message Box");
    QMessageBox::information(this,"Infomation消息框","Infomation消息框测试成功");
}

void Dialog::SlotWarningBtn()
{
    disLabel->setText("Warning Message Box");
    switch (QMessageBox::warning(this,"Warning消息框","是否删除MySQL数据库?",
 QMessageBox::Save | QMessageBox::Discard |QMessageBox::Cancel ,QMessageBox::Save)) {
    case QMessageBox::Save:
        disLabel->setText("你选择WarningMSG中Save按钮");
        break;
    case QMessageBox::Discard:
        disLabel->setText("你选择WarningMSG中Discard按钮");
        break;
    case QMessageBox::Cancel:
        disLabel->setText("你选择WarningMSG中Cancel按钮");
        break;
    default:
        break;
    }
}

void Dialog::SlotCriticalBtn()
{
    disLabel->setText("Critical Message Box");
    QMessageBox::critical(this,"Critical消息框","数据库文件备份错误，请重新检查!!!");
    return;
}

void Dialog::SlotAboutBtn()
{
    disLabel->setText("About Message Box");
    QMessageBox::about(this,"about消息框","about消息框测试");
    return;
}

void Dialog::SlotAboutQtBtn()
{
    disLabel->setText("About Message Box");
    QMessageBox::aboutQt(this,"about QT消息框测试");
    return;
}

