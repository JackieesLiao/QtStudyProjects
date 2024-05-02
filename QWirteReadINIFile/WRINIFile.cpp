#include "WRINIFile.h"
#include <QString>
#include <QStringList>
#include <QDebug>
void WriteIniFile()
{
    QSettings * configWriteIniFiles = new QSettings("MySQLFILES.ini",QSettings::IniFormat);
    //向INI文件写入配置信息
    //第一节参数
    configWriteIniFiles->setValue("/database/ip","192.168.1.41");
    configWriteIniFiles->setValue("/database/port","9527");
    configWriteIniFiles->setValue("/database/user","root");
    configWriteIniFiles->setValue("/database/password","123456");
    //第二节参数
    configWriteIniFiles->setValue("/notice/version","8.0");
    configWriteIniFiles->setValue("/notice/datetime","2024/05/02 19:48:29");
    //INI文件写入完成后，删除指针
    delete configWriteIniFiles;
    configWriteIniFiles = nullptr;
}

void ReadIniFile()
{
    QSettings * configReadIniFiles = new QSettings("MySQLFILES.ini",QSettings::IniFormat);
    QString str_ip = configReadIniFiles->value("/database/ip").toString();
    QString str_port = configReadIniFiles->value("/database/port").toString();
    QString str_root = configReadIniFiles->value("/database/user").toString();
    QString str_password = configReadIniFiles->value("/database/password").toString();
    QString version = configReadIniFiles->value("/notice/version").toString();
    QString datetime = configReadIniFiles->value("/notice/datetime").toString();
    qDebug() << "读取Ini配置如下：";
    qDebug() << "MySQL地址为：" << str_ip.toUtf8().data();
    qDebug() << "MySQL端口为：" << str_port.toUtf8().data();
    qDebug() << "MySQL用户名为：" <<str_root.toUtf8().data();
    qDebug() << "MySQL密码为：" << str_password.toUtf8().data();
    qDebug()<<"version:" << version.toUtf8().data();
    qDebug()<<"datetime:" << datetime.toUtf8().data();
    delete configReadIniFiles;
    configReadIniFiles = nullptr;
}

void ReadIniFileOnce()
{
    QSettings * setting = new QSettings("./MySQLFILES.ini",QSettings::IniFormat);
//    foreach (const QString& key, setting->allKeys()) {
//        qDebug() << key.toUtf8().data() << "," << setting->value(key).toString().toUtf8().data();
//    }
    QStringList keys = setting->allKeys();
    for(const auto&key : keys){
        qDebug() << key.toUtf8().data() << "," << setting->value(key).toString().toUtf8().data();
    }

    delete setting;
    setting = nullptr;
}
