#include "configwindow.h"
#include <QApplication>
#include <QStyleFactory>
#include <QtXml>
#include "manipuladorxml.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setStyle(QStyleFactory::create("Fusion"));
    ConfigWindow w;


    w.show();

    return a.exec();
}
