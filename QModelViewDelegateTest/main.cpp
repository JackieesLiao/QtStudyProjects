#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QFileSystemModel model;
    model.setRootPath("/"); // 设置根路径为根目录
    QTreeView tree_view;    //树视图
    QListView list_view;    //列表视图
    QTableView table_view;  //表视图
    //设置数据类型
    tree_view.setModel(&model);
    list_view.setModel(&model);
    table_view.setModel(&model);

    tree_view.setSelectionMode(QAbstractItemView::MultiSelection);
    list_view.setSelectionModel(tree_view.selectionModel());
    table_view.setSelectionModel(tree_view.selectionModel());
    //操作treeview后listview与tableview同步显示
    QObject::connect(&tree_view,&QTreeView::doubleClicked,&list_view,&QListView::setRootIndex);
    QObject::connect(&tree_view,&QTreeView::doubleClicked,&table_view,&QTableView::setRootIndex);

    QSplitter * splitter = new QSplitter;
    splitter->addWidget(&tree_view);
    splitter->addWidget(&list_view);
    splitter->addWidget(&table_view);
    splitter->setWindowTitle("模型测试操作");
    splitter->show();
    w.show();
    return a.exec();
}
