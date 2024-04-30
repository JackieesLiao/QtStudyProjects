#include "widget.h"
#include <QFile>
#include <QApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //1.创建QFile对象，指定操作的相关文件
    QFile qfs("D:\\QT_Dev\\Basics\\QFileTextTest\\text.txt");
    //2.打开文件进行写操作 ReadOnly ReadWrite Append Truncate
    if(!qfs.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append)){
        qDebug() << "打开文件失败，请重新检查";
    }
    else{
        qDebug() << "打开文件成功";
    }
    //3.向打开的文件写数据信息
    qfs.write("我爱你\n");
    qfs.write("pengyan\n");
    qfs.write("C++linux后台开发");
    //4.关闭文件
    qfs.close();
    //读取数据
    if(!qfs.open(QIODevice::ReadWrite|QIODevice::Text)){
        qDebug() << "打开文件失败，请重新检查";
    }
    else{
        qDebug() << "打开文件成功";
    }
    char * pStr = new char[200];
    qint64 read_count = qfs.readLine(pStr,200);
    while((read_count!=0)&&(read_count!=-1)){
        qDebug() << pStr;
        read_count = qfs.readLine(pStr,200);
    }
    Widget w;
    //w.show();
    return a.exec();
}
