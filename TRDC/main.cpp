#include "TRDC.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TRDC w;
    w.show();
    return a.exec();
}
