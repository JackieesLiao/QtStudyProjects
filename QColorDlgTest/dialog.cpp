#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("颜色对话框测试");
    pGridLay = new QGridLayout(this);
    pColorBtn = new QPushButton("调用颜色对话框");
    colorFrame = new QFrame;
    colorFrame->setFrameShape(QFrame::Box);
    colorFrame->setAutoFillBackground(true);// 填充背景处理

    pGridLay->addWidget(pColorBtn,0,0);
    pGridLay->addWidget(colorFrame,1,0);
    connect(pColorBtn,&QPushButton::clicked,this,&Dialog::SlotDisplayColorDlg);
}

Dialog::~Dialog()
{
}

void Dialog::SlotDisplayColorDlg()
{
    QColor colorVal = QColorDialog::getColor(Qt::green);
    if(colorVal.isValid()){
        colorFrame->setPalette(QPalette(colorVal));
    }
}
