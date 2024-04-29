#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    labelShapeArea = new PainterArea;
    pGridLay = new QGridLayout;
    setWindowTitle("Qt绘图框架测试:QPainter类");
    labelShape = new QLabel("绘制形状");//右侧有一个combox
    comboxShape = new QComboBox;
    comboxShape->addItem("Line",PainterArea::Line);
    comboxShape->addItem("rectangle",PainterArea::rectangle);
    connect(comboxShape,&QComboBox::activated,this,&Widget::SlotDisplayShape);
    pGridLay->addWidget(labelShape,0,0);
    pGridLay->addWidget(comboxShape,0,1);
    QHBoxLayout * mainLay = new QHBoxLayout(this);//整体布局
    mainLay->addWidget(labelShapeArea);
    mainLay->addLayout(pGridLay);

}

Widget::~Widget()
{
}

void Widget::SlotDisplayShape(int index)
{
    PainterArea::Shape sp = PainterArea::Shape(comboxShape->itemData(index,Qt::UserRole).toInt());
    labelShapeArea->setShape(sp);
}

