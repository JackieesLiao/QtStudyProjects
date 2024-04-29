#include "qfiledialog.h"
#include <QString>
#include <qfiledialog.h>
#include <QDebug>
QFileDialogx::QFileDialogx(QWidget *parent)
    : QDialog(parent)
{
    setFileLayoutFunc();
    connect(FileBrowseBtn,&QPushButton::clicked,this,&QFileDialogx::SlotGetFileInfo);
    connect(GetFileSizeBtn,&QPushButton::clicked,this,&QFileDialogx::SlotGetFileSize);
}

QFileDialogx::~QFileDialogx()
{
}

void QFileDialogx::setFileLayoutFunc()
{
    setWindowTitle("FileDlg类（文件对话框测试）");
    //1.创建控件
    FileNameLabel = new QLabel("文件名称:");
    FileNameEdit = new QLineEdit;
    FileBrowseBtn = new QPushButton("选择...");
    FileSizeLabel = new QLabel("文件大小:");
    FileSizeLabelLineEdit = new QLineEdit();
    GetFileSizeBtn = new QPushButton("获取文件大小");

    //2.排列布局
    QGridLayout * pGridLay = new QGridLayout;
    pGridLay->addWidget(FileNameLabel,0,0);
    pGridLay->addWidget(FileNameEdit,0,1);
    pGridLay->addWidget(FileBrowseBtn,0,2);
    pGridLay->addWidget(FileSizeLabel,1,0);
    pGridLay->addWidget(FileSizeLabelLineEdit,1,1,1,2);
    QHBoxLayout * pHBoxLay = new QHBoxLayout;
    pHBoxLay->addWidget(GetFileSizeBtn);
    QVBoxLayout *pVBoxLay = new QVBoxLayout(this);
    pVBoxLay->addLayout(pGridLay);
    pVBoxLay->addLayout(pHBoxLay);
}
//用于打开文件
void QFileDialogx::SlotGetFileInfo()
{
    QString StrFileName = QFileDialog::getOpenFileName(this,"打开","/","Files(*)");
    FileNameEdit->setText(StrFileName);
}
//用于获取文件大小
void QFileDialogx::SlotGetFileSize()
{
    //获取单行编辑框控件里面文件路径
    QString StrFileName = FileNameEdit->text();
    if(!StrFileName.isEmpty()){
        QFileInfo fileInfo(StrFileName);
        qint64 FileSize = fileInfo.size();
        FileSizeLabelLineEdit->setText(QString::number(FileSize));
    }else{
        qDebug() << "文件为空!";
    }
}

