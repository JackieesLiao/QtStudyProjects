#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
private:
    QLabel * labelMsg ,*labelDisPlayMsg;
    QPushButton * msgBtn;
    QGridLayout * pGridLay;
private slots:
    void SlotCustomMsg();
};
#endif // DIALOG_H
