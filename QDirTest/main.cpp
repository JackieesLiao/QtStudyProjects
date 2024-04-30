#include <QCoreApplication>
#include <QDir>
#include <QStringList>
#include <QString>
#include <QDebug>
//自定义函数实现获取目录大小
qint64 GetDirFileInfoSize(const QString& qpath)
{
    QDir dir(qpath);//专门用于操作获取路径名称，可使用相对或绝对路径
    qint64 qsize = 0;
    //使用foreach循环遍历文件夹中的每个文件。
    //dir.entryInfoList(QDir::Files)返回文件夹中所有文件的QFileInfo对象列表。
    //最后累加每个文件的大小
    foreach (QFileInfo info, dir.entryInfoList(QDir::Files)) {
        qsize = qsize + info.size();
    }
    foreach (QFileInfo s_dir, dir.entryInfoList(QDir::Dirs|QDir::NoDotAndDotDot)) {
        qsize = qsize + GetDirFileInfoSize(qpath + QDir::separator() + s_dir.filePath());
    }

    char uint = 'B';
    qint64 curDirSize = qsize;
    if(curDirSize > 1024){
        curDirSize /=1024;
        uint = 'K';
        if(curDirSize > 1024){
            curDirSize /=1024;
            uint = 'M';
            if(curDirSize > 1024){
                curDirSize /=1024;
                uint = 'G';
                if(curDirSize > 1024){
                    curDirSize /=1024;
                    uint = 'T';
                }
            }
        }
    }

    qDebug() << "目录占据空间为："<<curDirSize <<"\t" << qPrintable(qpath);
    return qsize;
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString path = QDir::currentPath();
    qDebug() << "当前路径为："<<path;
    GetDirFileInfoSize(path);
    return a.exec();
}
