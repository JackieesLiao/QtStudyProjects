#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    QPushButton *pBtn1;
    QPushButton *pBtn2;
private slots:
    //声明两个按钮的槽函数
    void SlotPushBtn1Clicked();
    void SlotPushBtn2Clicked();
};
#endif // WIDGET_H
