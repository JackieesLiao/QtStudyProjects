#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("员工信息");
    //将定义几个标签加入网格布局
    UserNumber = new QLabel("员工编号");
    UserNumberLineEdit = new QLineEdit;
    UserName = new QLabel("员工姓名");
    UserNameLineEdit = new QLineEdit();
    UserSex = new QLabel("员工性别");
    UserSexCombox = new QComboBox;
    UserSexCombox->addItem("男");
    UserSexCombox->addItem("女");
    Depart = new QLabel("所在部门");
    DepartTextEdit = new QTextEdit;
    UserAge = new QLabel("年龄");
    UserAgeLineEdit = new QLineEdit;
    //1.右边上布局设置
    topRightLayout = new QHBoxLayout();
    topRightLayout->setSpacing(25);
    myselfInfo = new QLabel("个人简历");
    mySelfInfoTextEdit = new QTextEdit;
    rightLayout = new QVBoxLayout();
    rightLayout->addLayout(topRightLayout);
    rightLayout->addWidget(myselfInfo);
    rightLayout->addWidget(mySelfInfoTextEdit);
    //3.右边下部分
    okBtn = new QPushButton("确认");
    cancelBtn = new QPushButton("取消");
    bottomLayout = new QHBoxLayout();
    bottomLayout->addStretch();
    bottomLayout->addWidget(okBtn);
    bottomLayout->addWidget(cancelBtn);
    //2.左边布局设置
    pGridLay = new QGridLayout();
    pGridLay->addWidget(UserNumber,0,0);
    pGridLay->addWidget(UserNumberLineEdit,0,1);
    pGridLay->addWidget(UserName,1,0);
    pGridLay->addWidget(UserNameLineEdit,1,1);
    pGridLay->addWidget(UserSex,2,0);
    pGridLay->addWidget(UserSexCombox,2,1);
    pGridLay->addWidget(Depart,3,0);
    pGridLay->addWidget(DepartTextEdit,3,1);
    pGridLay->addWidget(UserAge,4,0);
    pGridLay->addWidget(UserAgeLineEdit,4,1);

    pGridLay->setColumnStretch(0,1);
    pGridLay->setColumnStretch(1,3);

    QGridLayout*mLayout = new QGridLayout(this);

    mLayout->setSpacing(10);
    mLayout->addLayout(pGridLay,0,0);   //left
    mLayout->addLayout(rightLayout,0,1);//right
    mLayout->addLayout(bottomLayout,1,0,1,2);
    mLayout->setSizeConstraint(QLayout::SetFixedSize);
}

Dialog::~Dialog()
{
}

