#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QListWidget>     //列表框
#include <QListWidgetItem>
#include <QDir>
#include <QFileInfoList>   //获取指定目录的基本数据信息
#include <QVBoxLayout>     //垂直布局
#include <QString>
#include <QStringList>
class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
public:
    void displayFileInfoList(QFileInfoList list);
private:
    QLineEdit * fileLineEdit;    //显示所选择目录名称
    QListWidget * fileListWidget;//列表框
    QVBoxLayout * vBoxLay;
private slots:
    void displayDir(QDir * dir);
    void displayDirShow(QListWidgetItem *);
};
#endif // DIALOG_H
