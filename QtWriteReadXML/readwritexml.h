#ifndef READWRITEXML_H
#define READWRITEXML_H

#include <QDialog>
#include <QDomComment> //专门用于操作XML文件
#include <QDir>
#include <QDebug>
#include <QFile>
#include <QMessageBox>
QT_BEGIN_NAMESPACE
namespace Ui { class ReadWriteXML; }
QT_END_NAMESPACE

class ReadWriteXML : public QDialog
{
    Q_OBJECT

public:
    ReadWriteXML(QWidget *parent = nullptr);
    ~ReadWriteXML();
public:
    bool openXMLFile(QString fileNamePath);//根据路径打开文件
    void readXMLFile(); //读取xml文件
    void writeXMLFile();//写入xml文件
    void readRootXML(QDomNodeList nodeList);//读取子节点数据
private:
    QFile files_;
    QString current_filepath_;//当前文件路径
    QString current_filename_;//当前文件名
private:
    Ui::ReadWriteXML *ui;
private slots:
    void SlotWriteXML();
    void SlotReadXML();
};
#endif // READWRITEXML_H
