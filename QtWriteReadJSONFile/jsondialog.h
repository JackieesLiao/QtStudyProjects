#ifndef JSONDIALOG_H
#define JSONDIALOG_H

#include <QDialog>
#include <QString>
#include <QMessageBox>
#include <QFile>
#include <QDebug>
#include <QJsonDocument>   //JSON文档
#include <QJsonObject>     //JSON对象
#include <QJsonParseError> //JSON异常获取
QT_BEGIN_NAMESPACE
namespace Ui { class JsonDialog; }
QT_END_NAMESPACE

class JsonDialog : public QDialog
{
    Q_OBJECT

public:
    JsonDialog(QWidget *parent = nullptr);
    ~JsonDialog();

private slots:
    void SlotWriteJSONFile();
    void SlotReadJSONFile();
private:
    Ui::JsonDialog *ui;
};
#endif // JSONDIALOG_H
