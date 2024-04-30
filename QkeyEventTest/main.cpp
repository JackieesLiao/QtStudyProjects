#include "keyboardevent.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    KeyBoardEvent w;
    w.show();
    return a.exec();
}
