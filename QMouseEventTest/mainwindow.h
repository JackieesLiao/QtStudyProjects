#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qlabel.h>
#include <QMouseEvent> //鼠标事件
#include <QStatusBar>  //窗口状态栏
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void mouseMoveEvent(QMouseEvent * e) override;
    void mousePressEvent(QMouseEvent * e) override;
    void mouseReleaseEvent(QMouseEvent * e) override;

private:
    QLabel * statusLabel;
    QLabel * mouseLabelPos;
    void displayPicture();
};
#endif // MAINWINDOW_H
