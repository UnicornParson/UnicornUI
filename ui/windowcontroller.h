#ifndef WINDOWCONTROLLER_H
#define WINDOWCONTROLLER_H

#include <QObject>
#include <QQmlApplicationEngine>

#include "appskin.h"
#include "windowinfo.h"

class WindowController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QObject* wininfo READ wininfoobj NOTIFY wininfoChanged)
public:
    explicit WindowController(QObject *parent = nullptr);

    QString rootPath() const;
    void setRoot(const QString& path);
    bool start();

    int width() const;
    int height() const;
    QString title() const;
    QObject* wininfoobj();
    WindowInfo& info();
    AppSkin& skin();


    QVariant contextProperty(const QString &name) const;
    void setContextProperty(const QString &name, QObject *obj);
    void setContextProperty(const QString &name, const QVariant &v);

signals:
    void rootChanged(const QString& path);
    void quit();
    void exit(int retCode);
    void wininfoChanged(QObject* p);

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

#endif // WINDOWCONTROLLER_H
