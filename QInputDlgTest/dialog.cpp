#include "dialog.h"
#include <QString>
#include <qstringlist.h>
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    resize(260,110);
    setWindowTitle("标准输入对话框测试");
    pGridLay = new QGridLayout(this);
    inputStudentNumberBtn = new QPushButton;
    inputStudentNumberBtn->setText("学生学号");
    inputStudentNumberLineEdit = new QLineEdit("113523523");

    inputStudentNameBtn = new QPushButton("学生姓名");
    inputStudentNameLineEdit = new QLineEdit("pengyanliaojunjian");

    inputStudentSexBtn = new QPushButton("学生性别");
    inputStudentSexLineEdit = new QLineEdit("女");

    inputStudentScoreBtn = new QPushButton("学生分数");
    inputStudentScoreLineEdit = new QLineEdit("92");
    pGridLay->addWidget(inputStudentNumberBtn,0,0);
    pGridLay->addWidget(inputStudentNumberLineEdit,0,1);

    pGridLay->addWidget(inputStudentNameBtn,1,0);
    pGridLay->addWidget(inputStudentNameLineEdit,1,1);

    pGridLay->addWidget(inputStudentSexBtn,2,0);
    pGridLay->addWidget(inputStudentSexLineEdit,2,1);

    pGridLay->addWidget(inputStudentScoreBtn,3,0);
    pGridLay->addWidget(inputStudentScoreLineEdit,3,1);
    connect(inputStudentNumberBtn,&QPushButton::clicked,this,&Dialog::SlotInputStuNumber);
    connect(inputStudentNameBtn,&QPushButton::clicked,this,&Dialog::SlotInputStuName);
    connect(inputStudentSexBtn,&QPushButton::clicked,this,&Dialog::SlotInputStuSex);
    connect(inputStudentScoreBtn,&QPushButton::clicked,this,&Dialog::SlotInputStuScore);
}

Dialog::~Dialog()
{
}

void Dialog::SlotInputStuNumber()
{
    bool ok;
    QString number = QInputDialog::getText(this,"学号输入对话框","请输入学号",QLineEdit::Normal,
                                         QString(), &ok);
    if(ok && !number.isEmpty()){
        inputStudentNumberLineEdit->setText(number);
    }
    else{
        qDebug() << "请重新输入。";
    }
}

void Dialog::SlotInputStuName()
{
    bool ok;
    QString name = QInputDialog::getText(this,"姓名输入对话框","请输入姓名",QLineEdit::Normal,
                                         QString(), &ok);
    if(ok && !name.isEmpty()){
        inputStudentNameLineEdit->setText(name);
    }
    else{
        qDebug() << "请重新输入。";
    }
}

void Dialog::SlotInputStuSex()
{
    QStringList strSexItem;
    strSexItem << "男" << "女";
    bool ok;
    QString sex = QInputDialog::getItem(this,"性别输入对话框","请选择性别",strSexItem,0,
                                        false, &ok);
    if(ok && !sex.isEmpty()){
        inputStudentSexLineEdit->setText(sex);
    }
    else{
        qDebug() << "请重新输入。";
    }
}

void Dialog::SlotInputStuScore()
{
    bool ok;
    QString score = QInputDialog::getText(this,"分数输入对话框","请输入分数",QLineEdit::Normal,
                                         QString(), &ok);
    if(ok && !score.isEmpty()){
        inputStudentScoreLineEdit->setText(score);
    }
    else{
        qDebug() << "请重新输入。";
    }
}

