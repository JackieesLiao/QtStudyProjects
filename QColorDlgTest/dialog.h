#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QColorDialog>
#include <QFrame>
#include <QPushButton>
#include <QGridLayout>
class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
private:
    QGridLayout * pGridLay;
    QPushButton * pColorBtn;
    //QFrame类是基本控件的基类，QWidget是QFrame类型
    QFrame * colorFrame;
private slots:
    void SlotDisplayColorDlg();
};
#endif // DIALOG_H
