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
    QmlLogWrapper logWrp;
    logWrp.connect(&globals, &UnicornUIGlobal::uTrace, &logWrp, &QmlLogWrapper::onQmlTrace);
    logWrp.connect(&globals, &UnicornUIGlobal::uDebug, &logWrp, &QmlLogWrapper::onQmlDebug);
    logWrp.connect(&globals, &UnicornUIGlobal::uInfo, &logWrp, &QmlLogWrapper::onQmlInfo);
    logWrp.connect(&globals, &UnicornUIGlobal::uWarning, &logWrp, &QmlLogWrapper::onQmlWarning);
    logWrp.connect(&globals, &UnicornUIGlobal::uError, &logWrp, &QmlLogWrapper::onQmlError);
    logWrp.connect(&globals, &UnicornUIGlobal::uCritical, &logWrp, &QmlLogWrapper::onQmlCritical);
    logWrp.connect(&globals, &UnicornUIGlobal::uFatal, &logWrp, &QmlLogWrapper::onQmlFatal);

    QmlBootstrapper bootstarter;
    WindowController* win = bootstarter.createWindow();
    if(win == nullptr)
    {
        qWarning() << "cannot start ui";
        return -1;
    }
    return a.exec();
}
