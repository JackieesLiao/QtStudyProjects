#include "readwritexml.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ReadWriteXML w;
    w.show();
    return a.exec();
}
