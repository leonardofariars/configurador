#include "configwindow.h"
#include <QApplication>
#include <QtXml>
#include "manipuladorxml.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ConfigWindow w;
    ManipuladorXML c;
    c.LeArquivo();






    w.show();

    return a.exec();
}
