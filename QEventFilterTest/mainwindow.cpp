#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTransform>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Qt事件过滤器");
    //显示图片设置
    labelLeft = new QLabel;
    imageLeft.load(":/images/image/a.jpg");
    labelLeft->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    labelLeft->setPixmap(QPixmap::fromImage(imageLeft));
    labelMiddle = new QLabel;
    imageMiddle.load(":/images/image/b.jpg");
    labelMiddle->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    labelMiddle->setPixmap(QPixmap::fromImage(imageMiddle));
    labelRight = new QLabel;
    imageRight.load(":/images/image/c.jpg");
    labelRight->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    labelRight->setPixmap(QPixmap::fromImage(imageRight));
    //ui
    labelDisplayInfo = new QLabel("鼠标按键提示消息");
    labelDisplayInfo->setAlignment(Qt::AlignHCenter);


    QHBoxLayout * pHLay = new QHBoxLayout;
    pHLay->addWidget(labelLeft);
    pHLay->addWidget(labelMiddle);
    pHLay->addWidget(labelRight);
    //创建了一个包含垂直布局的 widget,并将一个水平布局和一个标签部件添加到该垂直布局中。
    QWidget * widget = new QWidget(this);
    QVBoxLayout * pVLay = new QVBoxLayout(widget);
    pVLay->addLayout(pHLay);
    pVLay->addWidget(labelDisplayInfo);
    //将这个 widget 设置为窗口的中央部件。
    setCentralWidget(widget);

    //安装事件过滤
    labelLeft->installEventFilter(this);
    labelMiddle->installEventFilter(this);
    labelRight->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
///事件过滤器：
/// 专门用于拦截传递到目标对象的事件，实现监控目标对象事件作用
/// 通过事件过滤器可以监控其他组件接收到的相关事件，QOject对象都可以
/// 作为事件过滤器来应用。事件过滤器在组件之前接收到事件，才能够决定是否
/// 将事件转发至某个组件对象。
///事件过滤处理
bool MainWindow::eventFilter(QObject * object, QEvent * event)
{
    if(object == labelLeft){
        if(event->type() == QEvent::MouseButtonPress){
            //鼠标按下，发生在窗户区域
            QMouseEvent * mouse_event = (QMouseEvent*)event;
            if(mouse_event->buttons() & Qt::LeftButton){
                //如果按下的是左键
                labelDisplayInfo->setText("鼠标左键被按下");
            }
            else if(mouse_event->buttons() & Qt::MiddleButton){
                //如果按下的是中键
                labelDisplayInfo->setText("鼠标中键被按下");
            }
            else if(mouse_event->buttons() & Qt::RightButton){
                //如果按下的是右键
                labelDisplayInfo->setText("鼠标右键被按下");
            }
            QTransform transform;
            transform.scale(1.5,1.5);
            QImage tempImage = imageLeft.transformed(transform);
            labelLeft->setPixmap(QPixmap::fromImage(tempImage));
        }
        if(event->type() ==QEvent::MouseButtonRelease){
            labelDisplayInfo->setText("鼠标按键已经释放");
            labelLeft->setPixmap(QPixmap::fromImage(imageLeft));
        }
    }
    else if(object == labelMiddle){
        if(event->type() == QEvent::MouseButtonPress){
            //鼠标按下，发生在窗户区域
            QMouseEvent * mouse_event = (QMouseEvent*)event;
            if(mouse_event->buttons() & Qt::LeftButton){
                //如果按下的是左键
                labelDisplayInfo->setText("鼠标左键被按下");
            }
            else if(mouse_event->buttons() & Qt::MiddleButton){
                //如果按下的是中键
                labelDisplayInfo->setText("鼠标中键被按下");
            }
            else if(mouse_event->buttons() & Qt::RightButton){
                //如果按下的是右键
                labelDisplayInfo->setText("鼠标右键被按下");
            }
            QTransform transform;
            transform.scale(3,3);
            QImage tempImage = imageMiddle.transformed(transform);
            labelMiddle->setPixmap(QPixmap::fromImage(tempImage));
        }
        if(event->type() ==QEvent::MouseButtonRelease){
            labelDisplayInfo->setText("鼠标按键已经释放");
            labelMiddle->setPixmap(QPixmap::fromImage(imageMiddle));
        }
    }
    else if(object == labelRight){
        if(event->type() == QEvent::MouseButtonPress){
            //鼠标按下，发生在窗户区域
            QMouseEvent * mouse_event = (QMouseEvent*)event;
            if(mouse_event->buttons() & Qt::LeftButton){
                //如果按下的是左键
                labelDisplayInfo->setText("鼠标左键被按下");
            }
            else if(mouse_event->buttons() & Qt::MiddleButton){
                //如果按下的是中键
                labelDisplayInfo->setText("鼠标中键被按下");
            }
            else if(mouse_event->buttons() & Qt::RightButton){
                //如果按下的是右键
                labelDisplayInfo->setText("鼠标右键被按下");
            }
            QTransform transform;
            transform.scale(1.5,1.5);
            QImage tempImage = imageRight.transformed(transform);
            labelRight->setPixmap(QPixmap::fromImage(tempImage));
        }
        if(event->type() ==QEvent::MouseButtonRelease){
            labelDisplayInfo->setText("鼠标按键已经释放");
            labelRight->setPixmap(QPixmap::fromImage(imageRight));
        }
    }
    return QMainWindow::eventFilter(object,event);
}

