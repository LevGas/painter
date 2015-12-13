#include "Painter.h"
#include <QApplication>
#include <QDebug>


int main(int argc, char *argv[])
{
    qDebug() << "+";
    QApplication a(argc, argv);
    CPainter p;
    p.show();
    qDebug() << "+";
    return a.exec();
}
