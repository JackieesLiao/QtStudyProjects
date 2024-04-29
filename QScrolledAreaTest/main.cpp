#include "widget.h"

#include <QApplication>
#include <QLabel>
#include <QScrollArea>
#include <QGridLayout>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.resize(600,600);
    QLabel*Label = new QLabel;
    Label->setScaledContents(true);
    QImage image(":/new/prefix1/images/STARRAIR.png");
    Label->setPixmap(QPixmap::fromImage(image));
    QScrollArea *sArea = new QScrollArea;
    //居中
    sArea->setAlignment(Qt::AlignCenter);
    //根据窗口比例显示
    //sArea->setWidgetResizable(true);
    sArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    sArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    sArea->setWidget(Label);
    QGridLayout*pGridLay = new QGridLayout();
    pGridLay->addWidget(sArea);
    w.setLayout(pGridLay);
    w.show();
    return a.exec();
}
