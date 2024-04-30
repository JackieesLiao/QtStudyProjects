#include "graphicswidget.h"

GraphicsWidget::GraphicsWidget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("GraphicsView图形视图框架测试");
    Angle_ = 2;
    scaleValue_ = 2;
    obliqueValue_ = 2;
    //场景
    QGraphicsScene * scene = new QGraphicsScene;
    scene->setSceneRect(-200,-200,-380,-380);
    QPixmap * pixmap = new QPixmap("C:\\Users\\liaojunjian1018\\Pictures\\wallhaven-zyr7jw.jpg");
    //图元
    pixItem = new PixItem(pixmap);
    scene->addItem(pixItem);//将图元添加到场景中
    pixItem->setPos(0,0);
    //视图
    view = new QGraphicsView;
    view->setScene(scene);
    view->setMinimumSize(800,600);

    controllFrame = new QFrame;
    CreateControllFrameFunc();

    //主窗体布局 让View和Fram成水平布局
    QHBoxLayout * hLay = new QHBoxLayout;
    hLay->addWidget(view);
    hLay->addWidget(controllFrame);

    setLayout(hLay);
}

GraphicsWidget::~GraphicsWidget()
{
}

void GraphicsWidget::CreateControllFrameFunc()
{
    //1.图片旋转区域设置
    QSlider * rotateSlider = new QSlider;//滑动条
    rotateSlider->setOrientation(Qt::Horizontal);
    rotateSlider->setRange(0,360);
    QHBoxLayout * rotateHLay = new QHBoxLayout;
    rotateHLay->addWidget(rotateSlider);
    QGroupBox * rotateGroup = new QGroupBox("图形旋转");
    rotateGroup->setLayout(rotateHLay);
    //2.缩放设置
    QSlider * scaleSlider = new QSlider;//滑动条
    scaleSlider->setOrientation(Qt::Horizontal);
    scaleSlider->setRange(0,2 * scaleValue_);
    scaleSlider->setValue(scaleValue_);
    QHBoxLayout * scaleHLay = new QHBoxLayout;
    scaleHLay->addWidget(scaleSlider);
    QGroupBox * scaleGroup = new QGroupBox("图形缩放");
    scaleGroup->setLayout(scaleHLay);
    //3.倾斜
    QSlider * obliqueSlider = new QSlider;//滑动条
    obliqueSlider->setOrientation(Qt::Horizontal);
    obliqueSlider->setRange(0,360);
    QHBoxLayout * obliqueHLay = new QHBoxLayout;
    obliqueHLay->addWidget(obliqueSlider);
    QGroupBox * obliqueGroup = new QGroupBox("图形倾斜");
    obliqueGroup->setLayout(obliqueHLay);

    connect(rotateSlider,&QSlider::valueChanged,this,&GraphicsWidget::SlotRotateFunc);
    connect(obliqueSlider,&QSlider::valueChanged,this,&GraphicsWidget::SlotObliqueFunc);
    connect(scaleSlider,&QSlider::valueChanged,this,&GraphicsWidget::SlotScaleFunc);

    QVBoxLayout * frameVLay = new QVBoxLayout;
    frameVLay->addWidget(rotateGroup);
    frameVLay->addWidget(scaleGroup);
    frameVLay->addWidget(obliqueGroup);
    controllFrame->setLayout(frameVLay);


}

void GraphicsWidget::SlotRotateFunc(int value)
{
    view->rotate(value - Angle_);
    Angle_ = value;
}

void GraphicsWidget::SlotScaleFunc(int value)
{
    qreal qs;
    if(value > scaleValue_){
        qs = pow(1.1,(value - scaleValue_));
    }
    else{
        qs = pow(1/1.1,(scaleValue_ - value));
    }
    view->scale(qs,qs);
    scaleValue_ = value;
}

void GraphicsWidget::SlotObliqueFunc(int value)
{
    view->shear((value-obliqueValue_)/2.0,0);
    obliqueValue_ = value;
}

