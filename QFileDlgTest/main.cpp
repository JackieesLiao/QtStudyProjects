#include "qfiledialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFileDialogx w;
    w.show();
    return a.exec();
}
