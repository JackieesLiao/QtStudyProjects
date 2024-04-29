#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("字体对话框测试");
    pGridLay = new QGridLayout(this);
    fontBtn = new QPushButton("调用字体对话框");
    fontLineEdit = new QLineEdit;
    fontLineEdit->setText("pengyan");
    pGridLay->addWidget(fontBtn,0,0);
    pGridLay->addWidget(fontLineEdit,0,1);
    connect(fontBtn,&QPushButton::clicked,this,&Dialog::SlotDisplayFont);
}

Dialog::~Dialog()
{
}

void Dialog::SlotDisplayFont()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok);
    if(ok){
        fontLineEdit->setFont(font);
    }else{
        qDebug() << "设置字体失败！";
    }
}

