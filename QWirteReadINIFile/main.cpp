#include <QCoreApplication>
#include "WRINIFile.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //写
    //WriteIniFile();
    //读
    //ReadIniFile();
    ReadIniFileOnce();
    return a.exec();
}
