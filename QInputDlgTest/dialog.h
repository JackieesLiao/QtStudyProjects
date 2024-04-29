#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QInputDialog>
class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
private:
    QGridLayout * pGridLay;
    QPushButton * inputStudentNumberBtn;
    QLineEdit * inputStudentNumberLineEdit;

    QPushButton * inputStudentNameBtn;
    QLineEdit *inputStudentNameLineEdit;

    QPushButton * inputStudentSexBtn;
    QLineEdit * inputStudentSexLineEdit;

    QPushButton * inputStudentScoreBtn;
    QLineEdit * inputStudentScoreLineEdit;
private slots:
    void SlotInputStuNumber();
    void SlotInputStuName();
    void SlotInputStuSex();
    void SlotInputStuScore();
};
#endif // DIALOG_H
