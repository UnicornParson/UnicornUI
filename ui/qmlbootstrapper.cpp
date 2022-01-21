#include "qmlbootstrapper.h"
#include "windowcontroller.h"
#include <QDebug>
namespace
{
const QString PlaceholderRoot("qrc:///qml/sampleRoot.qml");
}

QmlBootstrapper::QmlBootstrapper(QObject *parent) :
    QObject(parent)
{

}

QmlBootstrapper::~QmlBootstrapper()
{

}

WindowController* QmlBootstrapper::createWindow(const QString& rootPath, int width, int height, const QString& title, QObject *parent)
{
    WindowController* controller = new WindowController(parent);
    controller->setRoot(rootPath);
    if(rootPath.isEmpty())
    {
        controller->setRoot(PlaceholderRoot);
    }
    controller->info().setHeight(height);
    controller->info().setWidth(width);
    controller->info().setTitle(title);
    bool startRc = controller->start();
    if (startRc)
    {
        qDebug() << "controller started";
    }
    else
    {
        qWarning() << "cannot start window " << rootPath;
        controller->deleteLater();
        controller = nullptr;
    }
    return controller;
}
