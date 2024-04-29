#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QTextEdit>
#include <QPushButton>
#include <QGridLayout>
class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
private:
    //网格布局
    QGridLayout * pGridLay;
    //左边
    QLabel * UserNumber;
    QLineEdit * UserNumberLineEdit;
    QLabel * UserName;
    QLineEdit * UserNameLineEdit;
    QLabel * UserSex;
    QComboBox * UserSexCombox;
    QLabel * Depart;
    QTextEdit * DepartTextEdit;
    QLabel * UserAge;
    QLineEdit * UserAgeLineEdit;

    //右边:水平布局
    QHBoxLayout * topRightLayout;
    QVBoxLayout * rightLayout;
    QLabel * myselfInfo;
    QTextEdit * mySelfInfoTextEdit;

    //3.右边底部
    QPushButton * okBtn,*cancelBtn;
    QHBoxLayout * bottomLayout;
};
#endif // DIALOG_H
