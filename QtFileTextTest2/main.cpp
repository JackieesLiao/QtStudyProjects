#include <QCoreApplication>
#include <QFile>
#include <QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //将里面的数据写入文件
    qint32 qnumber[3] = {1,3,5};
    //将qnumber以二进制方式存储到字节数组中
    QByteArray bytearray;
    bytearray.resize(sizeof(qnumber));
    for(int i = 0;i<3;i++){
        memcpy(bytearray.data() + i * sizeof(qint32),&qnumber[i],sizeof(qint32));
    }
    //将bytearray数组存储至文件中
    QFile qfs("./QFileByteArray.dat");
    if(!qfs.open(QIODevice::ReadWrite | QIODevice::Text)){
        qDebug() << "打开失败";
    }else{
        qDebug() << "打开成功。";
    }
    qfs.write(bytearray);
    qfs.close();

    //先打开再读取
    qfs.open(QIODevice::ReadOnly);
    QByteArray byteArray = qfs.readAll();
    qDebug() << "byteArray:"<<byteArray;//二进制数据
    //将二进制转化为整数
    char *ctemp = byteArray.data();
    while(*ctemp){
        qDebug() << *(qint32*)ctemp;
        ctemp = ctemp + sizeof(qint32);
    }
    qfs.close();
    return a.exec();
}
