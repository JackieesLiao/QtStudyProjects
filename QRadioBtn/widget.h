#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QRadioButton>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    //声明两个单选框按钮
    QRadioButton *radioBtn1,*radioBtn2;
};
#endif // WIDGET_H
