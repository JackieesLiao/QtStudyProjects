#ifndef QFILEDIALOGX_H
#define QFILEDIALOGX_H

#include <QDialog>
#include <QFileDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout> //垂直布局
#include <QHBoxLayout> //水平
#include <QLineEdit>

class QFileDialogx : public QDialog
{
    Q_OBJECT

public:
    QFileDialogx(QWidget *parent = nullptr);
    ~QFileDialogx();
    void setFileLayoutFunc();
private:
    QLabel * FileNameLabel;
    QLineEdit * FileNameEdit;
    QPushButton * FileBrowseBtn;     //文件选择
    QLabel * FileSizeLabel;
    QLineEdit * FileSizeLabelLineEdit;//文件大小
    QPushButton * GetFileSizeBtn;     //获取文件大小

private slots:
    void SlotGetFileInfo();
    void SlotGetFileSize();
};
#endif // QFILEDIALOGX_H
