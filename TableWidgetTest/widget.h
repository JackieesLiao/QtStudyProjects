#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTabWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    QTabWidget* table_widget;
private slots:
    void SlotMsgCommitCliecked();
};
#endif // WIDGET_H
