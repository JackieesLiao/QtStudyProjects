#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //setWindowTitle("Splitter类拆分窗口测试");
    //1.分割窗口
    QSplitter *spMainWindow = new QSplitter(Qt::Horizontal,0);
    QTextEdit *textEdit = new QTextEdit("右边主窗口",spMainWindow);
    //2.拆分右边部分窗口
    QSplitter *spRight = new QSplitter(Qt::Vertical,spMainWindow);
    QTextEdit *textEditUp = new QTextEdit("右边上部分窗口",spRight);
    QTextEdit *textEditDown = new QTextEdit("右边下部分窗口",spRight);
    //3.
    QSplitter * sptest = new QSplitter(Qt::Vertical,spRight);
    QTextEdit * textEditTest = new QTextEdit("peng",sptest);
    //4.
    QSplitter * spTestEnd = new QSplitter(Qt::Horizontal,spMainWindow);
    QTextEdit * textEditEndTest = new QTextEdit("yan ",spTestEnd);
    spMainWindow->setWindowTitle("Splitter类拆分窗口测试");
    spMainWindow->show();

}

MainWindow::~MainWindow()
{
}

