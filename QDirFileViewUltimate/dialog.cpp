#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    resize(500,400);
    setWindowTitle("QDir类综合控件实战");
    fileLineEdit = new QLineEdit("/");
    fileListWidget = new QListWidget;
    vBoxLay = new QVBoxLayout(this);
    vBoxLay->addWidget(fileLineEdit);
    vBoxLay->addWidget(fileListWidget);

    //connect(fileLineEdit,&QLineEdit::returnPressed,this,&Dialog::displayDir);
    connect(fileListWidget,&QListWidget::itemDoubleClicked,this,&Dialog::displayDirShow);

    QString root = "/";
    QDir rootDir(root);
    QStringList str_list;
    str_list << "*";
    //entryInfoList函数获取过滤之后获得的文件名夹下面的信息列表
    QFileInfoList list = rootDir.entryInfoList(str_list);
    displayFileInfoList(list);
}

Dialog::~Dialog()
{
}
///显示目录和文件对应图标
void Dialog::displayFileInfoList(QFileInfoList list)
{
    fileListWidget->clear();
    for(unsigned int i =0;i<list.count();i++){
        QFileInfo tempFileInfo = list.at(i);
        if(tempFileInfo.isDir()){//如果是目录
            QIcon icon(":/images/images/folder.png");
            QString fileName = tempFileInfo.fileName();
            QListWidgetItem * temp = new QListWidgetItem(icon,fileName);
            fileListWidget->addItem(temp);
        }
        else if(tempFileInfo.isFile()){
            QIcon icon(":/images/images/document.png");
            QString fileName = tempFileInfo.fileName();
            QListWidgetItem * temp = new QListWidgetItem(icon,fileName);
            fileListWidget->addItem(temp);
        }
    }
}

void Dialog::displayDir(QDir * dir)
{
    QStringList str_list;
    str_list << "*";
    QFileInfoList fileInfoList = dir->entryInfoList(str_list,QDir::AllEntries,QDir::DirsFirst);
    displayFileInfoList(fileInfoList);
}

void Dialog::displayDirShow(QListWidgetItem *list_item)
{
    QDir dir;
    QString str = list_item->text();
    dir.setPath(fileLineEdit->text());
    dir.cd(str);
    fileLineEdit->setText(dir.absolutePath());
    displayDir(&dir);
}
