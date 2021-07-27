#include "mainwidget.h"
#include <QDebug>
#include <QApplication>
#include "qmlbootstrapper.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qDebug() << "create QmlBootstrapper";
    QmlBootstrapper bootstarter;
    bool startRc = bootstarter.start();
    if(!startRc)
    {
        qWarning() << "cannot start ui";
        return -1;
    }
    return a.exec();
}
