#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <qpushbutton.h>
#include <QGridLayout>
#include <QMessageBox>
class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
private:
    QLabel * disLabel;
    QGridLayout * pGridLay;
    QPushButton * questionBtn;//问题
    QPushButton * infoBtn;    //信息
    QPushButton * warningBtn; //警告消息框按钮
    QPushButton * criticalBtn;//错误消息框命令按钮
    QPushButton * aboutBtn;   //关于消息框命令按钮
    QPushButton * aboutQtBtn;
private slots:
    void SlotQuestionBtn();
    void SlotInfoBtn();
    void SlotWarningBtn();
    void SlotCriticalBtn();
    void SlotAboutBtn();
    void SlotAboutQtBtn();
};
#endif // DIALOG_H
