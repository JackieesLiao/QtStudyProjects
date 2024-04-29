#ifndef DIALOG_H
#define DIALOG_H
/*绘图原理双缓冲实战*/
#include <QDialog>
#include <QLabel>
#include <QGridLayout>
class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
private:
    QGridLayout * pGridLay;
    QLabel * labelGeometry;     //显示函数名称
    QLabel * labelGeometryValue;//显示Geometry获取的值
    QLabel * labelWidth;        //显示函数名称
    QLabel * labelWidthValue;   //显示Width获取的值
    QLabel * labelHeight;       //显示函数名称
    QLabel * labelHeightValue;  //显示Height获取的值
    QLabel * labelRect;         //显示函数名称
    QLabel * labelRectValue;    //显示Rect获取的值
    QLabel * labelSize;         //显示函数名称
    QLabel * labelSizeValue;    //显示Size获取的值
    //窗口大小,窗口大小发生变化时，触发该事件
    //通过该函数获取实时窗口的大小
    void resizeEvent(QResizeEvent *) override;
    //窗口移动事件
    //通过该函数获取实时窗口的位置
    void moveEvent(QMoveEvent *) override;
private slots:
    //更新标签的值
    void SlotUpdateLabel();
};
#endif // DIALOG_H
