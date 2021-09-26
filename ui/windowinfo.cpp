#include "windowinfo.h"
#include <QDebug>
#include "unicornuiglobal.h"

WindowInfo::WindowInfo(QObject *parent) :
    QObject(parent),
    m_Width(0),
    m_Height(0)
{

}

WindowInfo::WindowInfo(uint w, uint h, QObject *parent) :
    QObject(parent),
    m_Width(w),
    m_Height(h)
{

}

WindowInfo::WindowInfo(const WindowInfo& other):
    QObject(other.parent()),
    m_Width(other.m_Width),
    m_Height(other.m_Height),
    m_Title(other.m_Title),
    m_Name(other.m_Name)
{

}

WindowInfo& WindowInfo::operator=(const WindowInfo& other)
{
    if(this != &other)
    {
        setParent(other.parent());
        m_Width = other.m_Width;
        m_Height = other.m_Height;
        m_Title = other.m_Title;
        m_Name = other.m_Name;
    }
    return *this;
}

uint WindowInfo::Width() const
{
    return m_Width;
}

uint WindowInfo::Height() const
{
    return m_Height;
}

QString WindowInfo::Title() const
{
    return m_Title;
}

QString WindowInfo::Name() const
{
    return m_Name;
}

void WindowInfo::setWidth(uint v)
{
    if (m_Width != v)
    {
        m_Width = v;
        if(UnicornUIGlobal::self().propertyLoggingEnabled())
        {
            qDebug() << "m_Width" << "property changed. new value:" << m_Width;
        }
        emit WidthChanged(m_Width);
    }
}

void WindowInfo::setHeight(uint v)
{
    if (m_Height != v)
    {
        m_Height = v;
        if(UnicornUIGlobal::self().propertyLoggingEnabled())
        {
            qDebug() << "m_Height" << "property changed. new value:" << m_Height;
        }
        emit HeightChanged(m_Width);
    }
}

void WindowInfo::setTitle(QString v)
{
    if (m_Title != v)
    {
        m_Title = v;
        if(UnicornUIGlobal::self().propertyLoggingEnabled())
        {
            qDebug() << "m_Title" << "property changed. new value:" << m_Title;
        }
        emit TitleChanged(m_Title);
    }
}

void WindowInfo::setName(QString v)
{
    if (m_Name != v)
    {
        m_Name = v;
        if(UnicornUIGlobal::self().propertyLoggingEnabled())
        {
            qDebug() << "m_Name" << "property changed. new value:" << m_Name;
        }
        emit NameChanged(m_Name);
    }
}
