#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCheckBox>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    //1.声明一个QCheckBox对象
    QCheckBox*checkBox;
private slots:
    //声明QCheckBox槽函数，在操作过程中带参数传递，通过这个参数接收信号
    void SlotCheckBoxState(int);
};
#endif // MAINWINDOW_H
