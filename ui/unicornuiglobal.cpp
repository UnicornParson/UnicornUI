#include "unicornuiglobal.h"
#include <QDebug>

UnicornUIGlobal::UnicornUIGlobal(QObject *parent) :
    QObject(parent),
    m_debugGridEnabled(false),
    m_propertyLoggingEnabled(false),
  m_fpsBoosterEnabled(false)
{

}

UnicornUIGlobal& UnicornUIGlobal::self()
{
    static UnicornUIGlobal instance;
    return instance;
}

bool UnicornUIGlobal::debugGridEnabled() const
{
    return m_debugGridEnabled;
}

void UnicornUIGlobal::setDebugGridEnabled(bool v)
{
    if (m_debugGridEnabled != v)
    {
        m_debugGridEnabled = v;
        if (m_propertyLoggingEnabled)
        {
            qDebug() << "m_debugGridEnabled" << "property changed. new value:" << m_debugGridEnabled;
        }
        emit debugGridEnabledChanged(m_debugGridEnabled);
    }
}

bool UnicornUIGlobal::fpsBoosterEnabled() const
{
    return m_fpsBoosterEnabled;
}

void UnicornUIGlobal::setFpsBoosterEnabled(bool v)
{
    if (m_fpsBoosterEnabled != v)
    {
        m_fpsBoosterEnabled = v;
        if (m_fpsBoosterEnabled)
        {
            qDebug() << "m_fpsBoosterEnabled" << "property changed. new value:" << m_fpsBoosterEnabled;
        }
        emit fpsBoosterEnabledChanged(m_fpsBoosterEnabled);
    }
}

bool UnicornUIGlobal::propertyLoggingEnabled() const
{
    return m_propertyLoggingEnabled;
}

void UnicornUIGlobal::setPropertyLoggingEnabled(bool v)
{
    if (m_propertyLoggingEnabled != v)
    {
        m_propertyLoggingEnabled = v;
        if (m_propertyLoggingEnabled)
        {
            qDebug() << "m_propertyLoggingEnabled" << "property changed. new value:" << m_propertyLoggingEnabled;
        }
        emit propertyLoggingEnabledChanged(m_propertyLoggingEnabled);
    }
}
