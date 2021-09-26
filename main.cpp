#include "mainwidget.h"
#include <QDebug>
#include <QApplication>
#include "qmlbootstrapper.h"
#include "windowcontroller.h"
#include "unicornuiglobal.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qDebug() << "create QmlBootstrapper";
    UnicornUIGlobal& globals = UnicornUIGlobal::self();
    globals.setDebugGridEnabled(true);
    QmlBootstrapper bootstarter;
    WindowController* win = bootstarter.createWindow();
    if(win == nullptr)
    {
        qWarning() << "cannot start ui";
        return -1;
    }
    return a.exec();
}
