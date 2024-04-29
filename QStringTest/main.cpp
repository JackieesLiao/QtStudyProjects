#include <QCoreApplication>
#include <QString>
#include <QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    // 1 :QString 提供二元+操作符应用
    QString str = "LLL";
    str = str + "fds";
    qDebug() << str ;
    qDebug() << qPrintable(str);//去掉双引号

    //2.QString:append函数
    QString str1 = "Good";
    QString str2 = "bye";
    str1.append(str2);
    qDebug() << str1;
    return a.exec();
}
