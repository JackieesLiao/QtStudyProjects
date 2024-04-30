#ifndef GETFILEPROPERDLG_H
#define GETFILEPROPERDLG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QFileDialog>
#include <QDateTime>
#include <QHBoxLayout>
#include <QVBoxLayout>
class GetFileProperDlg : public QDialog
{
    Q_OBJECT

public:
    GetFileProperDlg(QWidget *parent = nullptr);
    ~GetFileProperDlg();
private:
    QLabel * labelFileName;
    QLineEdit * qlineEditFileName;
    QPushButton * getFileProBtn;
    //文件大小
    QLabel *labelFileSize;
    QLineEdit * qLineEditFileSize;
    //文件创建时间
    QLabel * labelCreatedTime;
    QLineEdit * qLineEditCreatedTime;
    //文件修改时间
    QLabel * labelModifiedTime;
    QLineEdit * qLineEditModifiedTime;
    //文件访问时间
    QLabel * labelAccessTime;
    QLineEdit * qLineEditAccessTime;
    //文件属性复选框
    QLabel * qLabelFileProperties;
    QCheckBox * CBIsFile;            //文件
    QCheckBox * CBIsHidden;          //隐藏属性
    QCheckBox * CBReadOnly;          //只读权限
    QCheckBox * CBWriteOnly;         //只写权限
    QCheckBox * CBExecutePermission; //执行权限
    QPushButton * getFilePropertiesBtn;
private slots:
    void SlotGetFilePathAndName();
    void SlotGetFileInfoProperties();
};
#endif // GETFILEPROPERDLG_H
