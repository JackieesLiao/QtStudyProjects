#include "keyboardevent.h"

KeyBoardEvent::KeyBoardEvent(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("键盘事件测试");
    setAutoFillBackground(true);

    QPalette palette = this->palette();
    palette.setColor(QPalette::Window,Qt::white);
    setPalette(palette);

    setMinimumSize(800,600);
    setMaximumSize(800,600);

    width = size().width();  //窗口宽度
    height = size().height();//窗口高度

    pix = new QPixmap(width,height);
    pix->fill(Qt::white);

    image.load(":/images/images/folder.png");
    image = image.scaled(50,50); // 设置图片的宽度和高度
    startX = 30;
    startY = 30;
    step = 30;

    drawPix();
    resize(800,600);
}

KeyBoardEvent::~KeyBoardEvent()
{
}

void KeyBoardEvent::drawPix()
{
    pix->fill(Qt::green);
    QPainter * painter = new QPainter;
    QPen pen(Qt::DashDotLine);
    for(int i = step;i<width;i+=step){//竖线
        painter->begin(pix);
        painter->setPen(pen);
        painter->drawLine(QPoint(i,0),QPoint(i,height));
        painter->end();
    }
    for(int j = step;j<height;j+=step){//横线
        painter->begin(pix);
        painter->setPen(pen);
        painter->drawLine(QPoint(0,j),QPoint(width,j));
        painter->end();
    }
    painter->begin(pix);
    painter->drawImage(QPoint(startX,startY),image);
    painter->end();
}

void KeyBoardEvent::paintEvent(QPaintEvent *e)
{
    QPainter painter;
    painter.begin(this);
    painter.drawPixmap(QPoint(0,0),*pix);
    painter.end();
}
///键盘按钮控制图片移动
void KeyBoardEvent::keyPressEvent(QKeyEvent * event)
{
    startX = startX - startX % step;
    startY = startY - startY % step;
    if(event->key() == Qt::Key_Left){
        startX = (startX - step < 0) ? startX : startX - step;
    }
    if(event->key() == Qt::Key_Right){
        startX = (startX + step + image.width() > width) ? startX : startX + step;
    }
    if(event->key() == Qt::Key_Up){
        startY = (startY - step < 0) ? startY : startY - step;
    }
    if(event->key() == Qt::Key_Down){
        startY = (startY + step + image.height() > height) ? startY : startY + step;
    }
    drawPix();
    qDebug() << startX <<" " << startY ;
    update();
}

