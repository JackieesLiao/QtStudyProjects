#include "getfileproperdlg.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GetFileProperDlg w;
    w.show();
    return a.exec();
}
