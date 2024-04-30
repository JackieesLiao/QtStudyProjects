#include "modelextend.h"

ModelExtend::ModelExtend(QObject *parent)
    : QAbstractTableModel{parent}
{
    empNo[1] = "231114234";
    empNo[2] = "231114235";
    empNo[3] = "231114236";
    empNo[4] = "231114237";
    empNo[5] = "231114238";

    empName[1] = "张三";
    empName[2] = "李四";
    empName[3] = "王五";
    empName[4] = "周润发";
    empName[5] = "周星驰";

    ModelFunc();
}

int ModelExtend::rowCount(const QModelIndex &parent) const
{
    return empIndex.size();
}

int ModelExtend::columnCount(const QModelIndex &parent) const
{
    return 3;//3列
}

QVariant ModelExtend::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()){
        return QVariant();//QVariant类包含QBrush,QColor,QRect
    }
    if(role == Qt::DisplayRole){
        switch (index.column()) {
        case 0:
            return empNo[empIndex[index.row()]];
            break;
        case 1:
            return empName[empNameIndex[index.row()]];
            break;
        case 2:
            return empDepartment[index.row()];
            break;
        default:
            return QVariant();
            break;
        }
    }
    return QVariant();
}

QVariant ModelExtend::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role == Qt::DisplayRole && orientation == Qt::Horizontal){
        return viewListTitle[section];
    }
    return QAbstractTableModel::headerData(section,orientation,role);
}

void ModelExtend::ModelFunc()
{
    viewListTitle << "员工编号" << "员工姓名" << "员工部门";
    empIndex << 1 << 2 <<3 << 4 <<5;
    empNameIndex << 1 << 2 << 3 << 4 << 5;
    empDepartment << "研发部" << "生产部" << "销售部" <<"财务部" <<"人力部";
}
