#include "stackeddlg.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StackedDlg w;
    w.show();
    return a.exec();
}
