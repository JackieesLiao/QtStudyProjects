#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    resize(300,160);
    setWindowTitle("QT窗口常用的API位置函数测试");
    pGridLay = new QGridLayout(this);
    labelGeometry = new QLabel("Geometry");
    labelGeometryValue = new QLabel;
    labelWidth = new QLabel("函数Width");
    labelWidthValue = new QLabel;
    labelHeight = new QLabel("函数Height");
    labelHeightValue = new QLabel;
    labelRect = new QLabel("函数Rect");
    labelRectValue = new QLabel;
    labelSize = new QLabel("函数Size");
    labelSizeValue = new QLabel;
    pGridLay->addWidget(labelGeometry,0,0);
    pGridLay->addWidget(labelGeometryValue,0,1);
    pGridLay->addWidget(labelWidth,1,0);
    pGridLay->addWidget(labelWidthValue,1,1);
    pGridLay->addWidget(labelHeight,2,0);
    pGridLay->addWidget(labelHeightValue,2,1);
    pGridLay->addWidget(labelRect,3,0);
    pGridLay->addWidget(labelRectValue,3,1);
    pGridLay->addWidget(labelSize,4,0);
    pGridLay->addWidget(labelSizeValue,4,1);
    SlotUpdateLabel();//更新label值
}

Dialog::~Dialog()
{
}

void Dialog::resizeEvent(QResizeEvent * )
{
    SlotUpdateLabel();
}

void Dialog::moveEvent(QMoveEvent * )
{
    SlotUpdateLabel();
}

void Dialog::SlotUpdateLabel()
{
    QString strGeometry;//专门存放geometry函数的显示结果
    QString str1,str2,str3,str4;
    strGeometry = str1.setNum(geometry().x()) + "," +
                  str2.setNum(geometry().y()) + "," +
                  str3.setNum(geometry().width()) + "," +
                  str4.setNum(geometry().height());

    labelGeometryValue->setText(strGeometry);//将获取到的值显示到label控件中

    QString strw,strh;//宽度、高度
    labelWidthValue->setText(strw.setNum(width()));
    labelHeightValue->setText(strh.setNum(height()));

    QString strrect;
    QString strrect1,strrect2,strrect3,strrect4;
    strrect = strrect1.setNum(rect().x()) + "," +
              strrect2.setNum(rect().y()) + "," +
              strrect3.setNum(width()) + "," +
              strrect4.setNum(height());
    labelRectValue->setText(strrect);

    QString strsize;
    QString strsize1,strsize2;
    strsize = strsize1.setNum(size().width()) + "," +
              strsize2.setNum(size().height());
    labelSizeValue->setText(strsize);
}
