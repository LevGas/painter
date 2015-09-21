#include "Painter.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CPainter p;
    p.show();

    return a.exec();
}
