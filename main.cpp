#include "configwindow.h"
#include <QApplication>
#include <QtXml>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ConfigWindow w;

    QString nome;

    QDomDocument conffile;


    w.show();

    return a.exec();
}
