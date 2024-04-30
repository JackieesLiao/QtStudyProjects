#ifndef MODELEXTEND_H
#define MODELEXTEND_H

#include <QAbstractTableModel>
#include <QVector>
#include <QVariant>
#include <QStringList>
#include <QMap>
class ModelExtend : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit ModelExtend(QObject *parent = nullptr);
    //行列统计
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index,int role) const;         //显示数据
    QVariant headerData(int section,Qt::Orientation,int role) const;//设置表头数据
private:
    QVector<short> empIndex;
    QVector<short> empNameIndex;

    QMap<short,QString> empNo;
    QMap<short,QString> empName;

    //QStringList提供一个字符串列表
    //QStringList添加QString字符串，直接用<<来添加字符串
    QStringList viewListTitle;      //标题名称
    QStringList empDepartment;
    void ModelFunc();
};

#endif // MODELEXTEND_H
