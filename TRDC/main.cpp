#include "core.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    system("chcp 65001");
    QApplication a(argc, argv);
    Core core;
    return a.exec();
}
