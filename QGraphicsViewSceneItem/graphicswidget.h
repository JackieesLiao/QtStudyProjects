#ifndef GRAPHICSWIDGET_H
#define GRAPHICSWIDGET_H
//创建一个类作为图元来显示对应图片
#include "pixitem.h"
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QFrame>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QSlider>
#include <math.h>
class GraphicsWidget : public QWidget
{
    Q_OBJECT

public:
    GraphicsWidget(QWidget *parent = nullptr);
    ~GraphicsWidget();
public:
    void CreateControllFrameFunc();
private:
    int Angle_;
    qreal scaleValue_;     //缩放
    qreal obliqueValue_;   //倾斜
    QGraphicsView * view;  //视图对象
    QFrame * controllFrame;//控制边框样式
    PixItem * pixItem;
private slots:
    void SlotRotateFunc(int);//旋转
    void SlotScaleFunc(int); //缩放
    void SlotObliqueFunc(int);//倾斜
};
#endif // GRAPHICSWIDGET_H
