#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QFontDialog>
#include <QLineEdit>
#include <QGridLayout>
class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
private:
    QGridLayout * pGridLay;
    QPushButton * fontBtn;
    QLineEdit * fontLineEdit;
private slots:
    void SlotDisplayFont();
};
#endif // DIALOG_H
