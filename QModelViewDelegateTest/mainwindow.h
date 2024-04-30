#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAbstractItemModel>
#include <QAbstractItemView>
#include <QAbstractItemDelegate>

#include <QSplitter>
#include <QDir>
#include <QFileSystemModel>
#include <QTreeView>
#include <QListView>
#include <QTableView>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H
