#ifndef KEYBOARDEVENT_H
#define KEYBOARDEVENT_H

#include <QWidget>
#include <QKeyEvent>  //键盘事件
#include <QPaintEvent>//绘图事件
#include <QPainter>
#include <QPen>
class KeyBoardEvent : public QWidget
{
    Q_OBJECT

public:
    KeyBoardEvent(QWidget *parent = nullptr);
    ~KeyBoardEvent();
public:
    void drawPix();
    void paintEvent(QPaintEvent*) override;
    virtual void keyPressEvent(QKeyEvent *event) override;
private:
    QPixmap * pix;
    QImage image;
    int startX,startY,width,height,step;
};
#endif // KEYBOARDEVENT_H
