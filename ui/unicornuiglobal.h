#ifndef UNICORNUIGLOBAL_H
#define UNICORNUIGLOBAL_H

#include <QObject>

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

class UnicornUIGlobal : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool debugGridEnabled READ debugGridEnabled WRITE setDebugGridEnabled NOTIFY debugGridEnabledChanged)
    Q_PROPERTY(bool propertyLoggingEnabled READ propertyLoggingEnabled WRITE setPropertyLoggingEnabled NOTIFY propertyLoggingEnabledChanged)
public:
    explicit UnicornUIGlobal(QObject *parent = nullptr);
    static UnicornUIGlobal& self();

    bool debugGridEnabled() const;
    void setDebugGridEnabled(bool v);

    bool propertyLoggingEnabled() const;
    void setPropertyLoggingEnabled(bool v);

signals:
    void debugGridEnabledChanged(bool v);
    void propertyLoggingEnabledChanged(bool v);

private:
    bool m_debugGridEnabled;
    bool m_propertyLoggingEnabled;
};

#endif // UNICORNUIGLOBAL_H
