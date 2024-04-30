#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QImage>   //Qt提供四个类处理图像数据：QImage,QPixmap,QBitmap,QPicture
#include <QMouseEvent>
#include <QEvent>
#include <QBoxLayout>//包含水平与垂直
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    QLabel * labelLeft;
    QLabel * labelMiddle;
    QLabel * labelRight;
    QLabel * labelDisplayInfo;

    QImage imageLeft;
    QImage imageMiddle;
    QImage imageRight;
private:
    Ui::MainWindow *ui;
public slots:
    bool eventFilter(QObject*,QEvent*);
};
#endif // MAINWINDOW_H
