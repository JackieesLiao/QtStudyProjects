#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDialogButtonBox>
#include <QPushButton>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    QDialogButtonBox *btnBox;
    QPushButton*pBtn;
private slots:
    void btnBoxClicked(QAbstractButton*);
};
#endif // WIDGET_H
