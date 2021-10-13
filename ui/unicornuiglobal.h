#ifndef UNICORNUIGLOBAL_H
#define UNICORNUIGLOBAL_H

#include <QObject>
#include <QDebug>
#ifndef MAYBE_UNUSED
#define MAYBE_UNUSED [[maybe_unused]]
#endif

#ifndef CONST_LITERAL
#define CONST_LITERAL MAYBE_UNUSED const QString
#endif

#ifndef CHANGE_VARIABLE
#define CHANGE_VARIABLE(name) \
    if(v != m_##name) { \
    m_##name = v; \
    if (UnicornUIGlobal::self().propertyLoggingEnabled()) \
{ qDebug() << #name << "property changed. new value:" << m_##name; } \
    emit name##Changed(m_##name); \
    }
#endif

class QmlLogWrapper : public QObject
{
    Q_OBJECT
public:
    explicit QmlLogWrapper(QObject *parent = nullptr):QObject(parent){}
    virtual ~QmlLogWrapper(){}
public slots:
    virtual void onQmlTrace(const QString& msg){qDebug() << "[QML_TRACE]" << msg;}
    virtual void onQmlDebug(const QString& msg){qDebug() << "[QML_DEBUG]" << msg;}
    virtual void onQmlInfo(const QString& msg){qInfo() << "[QML_INFO]" << msg;}
    virtual void onQmlWarning(const QString& msg){qWarning() << "[QML_WARNING]" << msg;}
    virtual void onQmlError(const QString& msg){qWarning() << "[QML_ERROR]" << msg;}
    virtual void onQmlCritical(const QString& msg){qCritical() << "[QML_CRITICAL]" << msg;}
    virtual void onQmlFatal(const QString& msg){qFatal("[QML_FATAL] %s", msg.toLatin1().data());}
};

class UnicornUIGlobal : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool debugGridEnabled READ debugGridEnabled WRITE setDebugGridEnabled NOTIFY debugGridEnabledChanged)
    Q_PROPERTY(bool propertyLoggingEnabled READ propertyLoggingEnabled WRITE setPropertyLoggingEnabled NOTIFY propertyLoggingEnabledChanged)
    Q_PROPERTY(bool fpsBoosterEnabled READ fpsBoosterEnabled WRITE setFpsBoosterEnabled NOTIFY fpsBoosterEnabledChanged)
    Q_PROPERTY(bool fpsIndicatorEnabled READ fpsIndicatorEnabled WRITE setFpsIndicatorEnabled NOTIFY fpsIndicatorEnabledChanged)
public:

    explicit UnicornUIGlobal(QObject *parent = nullptr);
    static UnicornUIGlobal& self();

    bool fpsIndicatorEnabled() const;
    Q_INVOKABLE void setFpsIndicatorEnabled(bool v);

    bool debugGridEnabled() const;
    Q_INVOKABLE void setDebugGridEnabled(bool v);

    bool propertyLoggingEnabled() const;
    Q_INVOKABLE void setPropertyLoggingEnabled(bool v);

    bool fpsBoosterEnabled() const;
    Q_INVOKABLE void setFpsBoosterEnabled(bool v);

signals:
    void debugGridEnabledChanged(bool v);
    void propertyLoggingEnabledChanged(bool v);
    void fpsBoosterEnabledChanged(bool v);
    void fpsIndicatorEnabledChanged(bool v);

    void uTrace(const QString& msg);
    void uDebug(const QString& msg);
    void uInfo(const QString& msg);
    void uWarning(const QString& msg);
    void uError(const QString& msg);
    void uCritical(const QString& msg);
    void uFatal(const QString& msg);

private:
    UnicornUIGlobal(const UnicornUIGlobal&) = delete;
    UnicornUIGlobal(const UnicornUIGlobal&&) = delete;
    UnicornUIGlobal& operator=(const UnicornUIGlobal&) = delete;

    bool m_debugGridEnabled;
    bool m_propertyLoggingEnabled;
    bool m_fpsBoosterEnabled;
    bool m_fpsIndicatorEnabled;
};

#endif // UNICORNUIGLOBAL_H
