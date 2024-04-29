#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <qcommandlinkbutton.h>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    //声明一个QCommandLinkButton对象
    QCommandLinkButton *clb;
private slots:
    //鼠标点击clb之后触发
    void SlotClbClicked();
};
#endif // WIDGET_H
