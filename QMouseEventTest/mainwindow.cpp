#include "mainwindow.h"
#include <QString>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("测试鼠标事件");
    resize(800,600);
    statusLabel = new QLabel;
    statusLabel->setText("鼠标当前窗口坐标为：");
    statusLabel->setFixedWidth(200);

    mouseLabelPos = new QLabel;
    mouseLabelPos->setText("");
    mouseLabelPos->setFixedWidth(200);

    //在状态栏中添加窗口小控件对象
    statusBar()->addPermanentWidget(statusLabel);
    statusBar()->addPermanentWidget(mouseLabelPos);

    //鼠标实时追踪
    this->setMouseTracking(true);
    displayPicture();
}

MainWindow::~MainWindow()
{
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    mouseLabelPos->setText("("+
                           QString::number(e->position().x())+","+
                           QString::number(e->position().y())+")");
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    QString qstr = "("+
                   QString::number(e->position().x())+","+
                   QString::number(e->position().y())+")";
    if(e->button() == Qt::LeftButton){
        statusBar()->showMessage("用户已按下鼠标左键坐标"+qstr);
    }else if(e->button() == Qt::RightButton){
        statusBar()->showMessage("用户已按下鼠标右键坐标"+qstr);
    }else if(e->button() == Qt::MiddleButton){
        statusBar()->showMessage("用户已按下鼠标中键坐标"+qstr);
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    QString qstr = "("+
                    QString::number(e->position().x())+","+
                    QString::number(e->position().y())+")";
    statusBar()->showMessage("用户已释放鼠标坐标"+qstr,20);
}

void MainWindow::displayPicture()
{
    QString filename("C:\\Users\\liaojunjian1018\\Pictures\\wallhaven-gpde3d.jpg");
    QImage * image = new QImage;
    QLabel * imageLabel = new QLabel(this);
    imageLabel->move(20,20);
    imageLabel->setFixedSize(400,200);
    if(!(image->load(filename))){
        QMessageBox::information(this,"失败","加载图片失败，请重新检查");
        delete image;
        return;
    }
    imageLabel->setPixmap(QPixmap::fromImage(*image));
}

