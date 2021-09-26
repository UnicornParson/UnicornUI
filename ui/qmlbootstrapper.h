#ifndef QMLBOOTSTRAPPER_H
#define QMLBOOTSTRAPPER_H

#include <QObject>
#include <QtQml/QQmlApplicationEngine>


class WindowController;
class QmlBootstrapper : public QObject
{
    Q_OBJECT
public:
    explicit QmlBootstrapper(QObject *parent = nullptr);
    ~QmlBootstrapper();
    WindowController* createWindow(const QString& rootPath = "", int width = 0, int height = 0, const QString& title = "", QObject *parent = nullptr);




};

#endif // QMLBOOTSTRAPPER_H
