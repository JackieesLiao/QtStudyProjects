#ifndef GRAPHICSWIDGET_H
#define GRAPHICSWIDGET_H
//创建一个类作为图元来显示对应图片
#include <QWidget>

class GraphicsWidget : public QWidget
{
    Q_OBJECT

public:
    GraphicsWidget(QWidget *parent = nullptr);
    ~GraphicsWidget();
};
#endif // GRAPHICSWIDGET_H
