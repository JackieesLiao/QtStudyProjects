#ifndef MAINWINDOW_H
#define MAINWINDOW_H
/*双缓冲绘图实现*/
#include "drawwidget.h"
#include <QMainWindow>
#include <QLabel>
#include <QComboBox>  //下拉框
#include <QToolButton>//工具按钮
#include <QToolBar>//标题栏
#include <QSpinBox>//
#include <QColorDialog>//颜色对话框
#include <QGridLayout> //网格布局
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void CreateToolBar();
private:
    DrawWidget * drawWidget;
    QLabel * labelStyle;          //线型风格
    QComboBox * comboxLabelStyle; //下拉框
    QLabel * labelWidth;
    QSpinBox * spinboxLabelWidth;
    QToolButton *colorBtn;
    QToolButton *clearBtn;
private slots:
    void displayStyle();
    void displayColor();
};
#endif // MAINWINDOW_H
