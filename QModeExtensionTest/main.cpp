#include "mainwindow.h"
#include "modelextend.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    ModelExtend model;
    QTableView view;
    view.setModel(&model);
    view.setWindowTitle("Model扩展测试");
    view.resize(500,300);
    view.show();
    return a.exec();
}
