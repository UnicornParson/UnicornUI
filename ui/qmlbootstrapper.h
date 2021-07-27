#ifndef QMLBOOTSTRAPPER_H
#define QMLBOOTSTRAPPER_H

#include <QObject>
#include <QtQml/QQmlApplicationEngine>

#include "appskin.h"
#include "windowinfo.h"
class QmlBootstrapper : public QObject
{
    Q_OBJECT
public:
    explicit QmlBootstrapper(QObject *parent = nullptr);
    ~QmlBootstrapper();
    bool start();
    QString rootPath() const;
    void setRoot(const QString& path);
signals:
    void rootChanged(const QString& path);
    void quit();
    void exit(int retCode);

public slots:
    void onQmlWarnings(const QList<QQmlError> &warnings);
    void onQuit();
    void onExit(int retCode);
private:
    void createEngine();
    void destroyEngine();

    AppSkin m_skin;
    WindowInfo m_winInfo;
    QQmlApplicationEngine *m_qmlEngine;
    QString m_rootPath;
};

#endif // QMLBOOTSTRAPPER_H
