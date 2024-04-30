#include "getfileproperdlg.h"

GetFileProperDlg::GetFileProperDlg(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("获取文件属性项目实战模块");
    labelFileName = new QLabel("文件路径名称");
    qlineEditFileName = new QLineEdit;
    getFileProBtn = new QPushButton("打开文件...");

    //文件大小
    labelFileSize = new QLabel("文件容量大小:");
    qLineEditFileSize = new QLineEdit;
    //文件创建时间
    labelCreatedTime = new QLabel("文件创建时间:");
    qLineEditCreatedTime = new QLineEdit;
    //文件修改时间
    labelModifiedTime = new QLabel("文件修改时间:");
    qLineEditModifiedTime= new QLineEdit;
    //文件访问时间
    labelAccessTime = new QLabel("文件访问时间:");
    qLineEditAccessTime = new QLineEdit;

    qLabelFileProperties = new QLabel("文件属性");
    CBIsFile = new QCheckBox("文件");
    CBIsHidden = new QCheckBox("隐藏属性");;          //隐藏属性
    CBReadOnly = new QCheckBox("只读权限");;          //只读权限
    CBWriteOnly = new QCheckBox("只写权限");;         //只写权限
    CBExecutePermission = new QCheckBox("执行权限");; //执行权限
    getFilePropertiesBtn = new QPushButton("获取文件属性的全部数据信息");

    QGridLayout * pGridLay = new QGridLayout;
    pGridLay->addWidget(labelFileName,0,0);
    pGridLay->addWidget(qlineEditFileName,0,1);
    pGridLay->addWidget(getFileProBtn,0,2);
    pGridLay->addWidget(labelFileSize,1,0);
    pGridLay->addWidget(qLineEditFileSize,1,1,1,2);
    pGridLay->addWidget(labelCreatedTime,2,0);
    pGridLay->addWidget(qLineEditCreatedTime,2,1,1,2);
    pGridLay->addWidget(labelModifiedTime,3,0);
    pGridLay->addWidget(qLineEditModifiedTime,3,1,1,2);
    pGridLay->addWidget(labelAccessTime,4,0);
    pGridLay->addWidget(qLineEditAccessTime,4,1,1,2);

    //给复选框加入水平布局中
    QHBoxLayout * hLay = new QHBoxLayout;
    hLay->addWidget(qLabelFileProperties);
    hLay->addStretch();
    QHBoxLayout * hLayCheck = new QHBoxLayout;
    hLayCheck->addWidget(CBIsFile);
    hLayCheck->addWidget(CBIsHidden);
    hLayCheck->addWidget(CBReadOnly);
    hLayCheck->addWidget(CBWriteOnly);
    hLayCheck->addWidget(CBExecutePermission);
    QHBoxLayout * hLayBtn = new QHBoxLayout;
    hLayBtn->addWidget(getFilePropertiesBtn);
    //整体垂直布局
    QVBoxLayout * vLay = new QVBoxLayout(this);
    vLay->addLayout(pGridLay);
    vLay->addLayout(hLay);
    vLay->addLayout(hLayCheck);
    vLay->addLayout(hLayBtn);

    connect(getFileProBtn,&QPushButton::clicked,this,&GetFileProperDlg::SlotGetFilePathAndName);
    connect(getFilePropertiesBtn,&QPushButton::clicked,this,&GetFileProperDlg::SlotGetFileInfoProperties);
}

GetFileProperDlg::~GetFileProperDlg()
{
}

void GetFileProperDlg::SlotGetFilePathAndName()
{
    QString filepath;
    filepath = QFileDialog::getOpenFileName(this,"打开文件对话框","/","files(*)");
    qlineEditFileName->setText(filepath);
}

void GetFileProperDlg::SlotGetFileInfoProperties()
{
    QString strFile = qlineEditFileName->text();
    QFileInfo fileInfo(strFile);
    qint64 fileSize = fileInfo.size();//文件大小
    qLineEditFileSize->setText(QString::number(fileSize));
    QDateTime createdTime = fileInfo.birthTime();
    qLineEditCreatedTime->setText(createdTime.toString());
    QDateTime modifiedTime = fileInfo.lastModified();
    QDateTime accessTime = fileInfo.lastRead();
    qLineEditModifiedTime->setText(modifiedTime.toString());
    qLineEditAccessTime->setText(accessTime.toString());

    bool isFile = fileInfo.isFile();
    bool isHidden = fileInfo.isHidden();
    bool isReadOnly = fileInfo.isReadable();
    bool isWriteOnly = fileInfo.isWritable();
    bool isExecutable = fileInfo.isExecutable();

    ///根据获取的文件属性信息设置复选框状态
    CBIsFile->setCheckState(isFile ? Qt::Checked : Qt::Unchecked);
    CBIsHidden->setCheckState(isHidden ? Qt::Checked : Qt::Unchecked);
    CBReadOnly->setCheckState(isReadOnly ? Qt::Checked : Qt::Unchecked);
    CBWriteOnly->setCheckState(isWriteOnly ? Qt::Checked : Qt::Unchecked);
    CBExecutePermission->setCheckState(isExecutable ? Qt::Checked : Qt::Unchecked);
}
