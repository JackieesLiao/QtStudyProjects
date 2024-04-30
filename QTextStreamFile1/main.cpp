#include <QCoreApplication>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QDataStream>
#include <QString>
//文本文件读取
static void readwriteTextFileStream()
{
    //向文件写入数据
    QFile qfs("./qtextstream.txt");
    if(!qfs.open(QIODevice::WriteOnly|QIODevice::Text)){
        qDebug() << "打开文本文件失败，请重新检查";
    }else{
        qDebug() << "打开成功。";
    }

    QTextStream qtext(&qfs);
    qtext << (QString)"C++开发真他妈难";
    qfs.close();
    //读取文件数据
    if(!qfs.open(QIODevice::ReadOnly|QIODevice::Text)){
        qDebug() << "打开文本文件失败，请重新检查";
    }else{
        qDebug() << "打开文件成功，读取文件中....";
    }
    QTextStream read_text(&qfs);
    while(!read_text.atEnd()){
        QString str;
        read_text >> str;
        qDebug() << str;
    }
    qfs.close();
}
//二进制文件读取
static void readwriteBinFileStream()
{
    // 创建一个QFile对象
    QFile file("./binary_file.dat");
    if(!file.open(QIODevice::WriteOnly)){
        qDebug() << "打开文本文件失败，请重新检查";
    }else{
        qDebug() << "打开成功。";
    }
    QDataStream data_stream(&file);
    data_stream.setVersion(QDataStream::Qt_6_6);
    QByteArray dataToWrite = "Hello, Binary World!";
    data_stream << dataToWrite;
    file.close();

    if(!file.open(QIODevice::ReadOnly)){
        qDebug() << "打开文本文件失败，请重新检查";
    }else{
        qDebug() << "打开成功,二进制文件读取中...";
    }
    QDataStream in(&file);

    // 设置读取二进制数据的版本
    in.setVersion(QDataStream::Qt_5_0);

    // 读取数据
    QByteArray data;
    in >> data;
    qDebug() <<"data:" <<data;
    // 关闭文件
    file.close();
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    readwriteTextFileStream();
    readwriteBinFileStream();
    return a.exec();
}
