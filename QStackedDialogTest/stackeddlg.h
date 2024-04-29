#ifndef STACKEDDLG_H
#define STACKEDDLG_H

#include <QMainWindow>
#include <QDialog>
#include <QListWidget>
#include <QStackedWidget>
#include <QLabel>
class StackedDlg : public QDialog
{
    Q_OBJECT

public:
    StackedDlg(QWidget *parent = nullptr);
    ~StackedDlg();
public:
    QStackedWidget * stacks;
    QListWidget * qList;
    QLabel * label1,*label2,*label3,*label4,*label5;
};
#endif // STACKEDDLG_H
