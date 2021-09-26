#include "appskin.h"
#include "QStringLiteral"
#include "QString"
#include <QDebug>
#include "unicornuiglobal.h"


namespace DefaultSkin
{
CONST_LITERAL DefaultBackgroundColor("white");
CONST_LITERAL DefaultFontColor("black");
CONST_LITERAL DefaultButtonBackgroundColor("#C5D3E2");
CONST_LITERAL DefaultButtonFontColor("#5C6A79");
CONST_LITERAL DefaultButtonBorderColor("#5C6A79");
CONST_LITERAL DefaultButtonHoveredBackgroundColor("#5C6A79");
CONST_LITERAL DefaultButtonHoveredFontColor("#C5D3E2");
CONST_LITERAL DefaultButtonHoveredBorderColor("#C5D3E2");
CONST_LITERAL DefaultButtonDisabledBackgroundColor("#E0E0E0");
CONST_LITERAL DefaultButtonDisabledFontColor("#D0D0D0");
CONST_LITERAL DefaultButtonDisabledBorderColor("#D0D0D0");
constexpr int DefaultMargin = 2;
constexpr int DefaultBorderSize = 1;
constexpr int DefaultBorderRadius = 5;
}

AppSkin::AppSkin(QObject *parent) :
    QObject(parent),
    m_backgroundColor(DefaultSkin::DefaultBackgroundColor),
    m_mainFontColor(DefaultSkin::DefaultFontColor),
    m_buttonBackgroundColor(DefaultSkin::DefaultButtonBackgroundColor),
    m_buttonFontColor(DefaultSkin::DefaultButtonFontColor),
    m_buttonBorderColor(DefaultSkin::DefaultButtonBorderColor),
    m_buttonHoveredBackgroundColor(DefaultSkin::DefaultButtonHoveredBackgroundColor),
    m_buttonHoveredFontColor(DefaultSkin::DefaultButtonHoveredFontColor),
    m_buttonHoveredBorderColor(DefaultSkin::DefaultButtonHoveredBorderColor),
    m_buttonDisabledBackgroundColor(DefaultSkin::DefaultButtonDisabledBackgroundColor),
    m_buttonDisabledFontColor(DefaultSkin::DefaultButtonDisabledFontColor),
    m_buttonDisabledBorderColor(DefaultSkin::DefaultButtonDisabledBorderColor),
    m_defaultMargin(DefaultSkin::DefaultMargin),
    m_defaultBorderSize(DefaultSkin::DefaultBorderSize),
    m_defaultBorderRadius(DefaultSkin::DefaultBorderRadius)
{

}

bool AppSkin::loadFromFile(const QString& path)
{
    Q_UNUSED(path)
    // TODO: json loader
    return false;
}

QString AppSkin::backgroundColor() const
{
    return m_backgroundColor;
}

QString AppSkin::mainFontColor() const
{
    return m_mainFontColor;
}

QString AppSkin::buttonBackgroundColor() const
{
    return m_buttonBackgroundColor;
}

QString AppSkin::buttonFontColor() const
{
    return m_buttonFontColor;
}

QString AppSkin::buttonBorderColor() const
{
    return m_buttonBorderColor;
}

QString AppSkin::buttonHoveredBackgroundColor() const
{
    return m_buttonHoveredBackgroundColor;
}

QString AppSkin::buttonHoveredFontColor() const
{
    return m_buttonHoveredFontColor;
}

QString AppSkin::buttonHoveredBorderColor() const
{
    return m_buttonHoveredBorderColor;
}

QString AppSkin::buttonDisabledBackgroundColor() const
{
    return m_buttonDisabledBackgroundColor;
}

QString AppSkin::buttonDisabledFontColor() const
{
    return m_buttonDisabledFontColor;
}

QString AppSkin::buttonDisabledBorderColor() const
{
    return m_buttonDisabledBorderColor;
}

int AppSkin::defaultMargin() const
{
    return m_defaultMargin;
}

int AppSkin::defaultBorderSize() const
{
    return m_defaultBorderSize;
}

int AppSkin::defaultBorderRadius() const
{
    return m_defaultBorderRadius;
}

void AppSkin::setBackgroundColor(const QString& v)
{
    m_backgroundColor = v;
    if(UnicornUIGlobal::self().propertyLoggingEnabled())
    {
        qDebug() << "backgroundColor" << "property changed. new value:" << m_backgroundColor;
    }
    emit backgroundColorChanged(m_backgroundColor);
}

void AppSkin::setMainFontColor(const QString& v)
{
    m_mainFontColor = v;
    if(UnicornUIGlobal::self().propertyLoggingEnabled())
    {
        qDebug() << "m_mainFontColor" << "property changed. new value:" << m_mainFontColor;
    }
    emit mainFontColorChanged(m_mainFontColor);
}

void AppSkin::setButtonBackgroundColor(const QString& v)
{
    m_buttonBackgroundColor = v;
    if(UnicornUIGlobal::self().propertyLoggingEnabled())
    {
        qDebug() << "m_buttonBackgroundColor" << "property changed. new value:" << m_buttonBackgroundColor;
    }
    emit buttonBackgroundColorChanged(m_buttonBackgroundColor);
}

void AppSkin::setButtonFontColor(const QString& v)
{
    m_buttonFontColor = v;
    if(UnicornUIGlobal::self().propertyLoggingEnabled())
    {
        qDebug() << "m_buttonFontColor" << "property changed. new value:" << m_buttonFontColor;
    }
    emit buttonFontColorChanged(m_buttonFontColor);
}

void AppSkin::setButtonBorderColor(const QString& v)
{
    m_buttonBorderColor = v;
    if(UnicornUIGlobal::self().propertyLoggingEnabled())
    {
        qDebug() << "m_buttonBorderColor" << "property changed. new value:" << m_buttonBorderColor;
    }
    emit buttonBorderColorChanged(m_buttonBorderColor);
}

void AppSkin::setButtonHoveredBackgroundColor(const QString& v)
{
    m_buttonHoveredBackgroundColor = v;
    if(UnicornUIGlobal::self().propertyLoggingEnabled())
    {
        qDebug() << "m_buttonHoveredBackgroundColor" << "property changed. new value:" << m_buttonHoveredBackgroundColor;
    }
    emit buttonHoveredBackgroundColorChanged(m_buttonHoveredBackgroundColor);
}

void AppSkin::setButtonHoveredFontColor(const QString& v)
{
    m_buttonHoveredFontColor = v;
    if(UnicornUIGlobal::self().propertyLoggingEnabled())
    {
        qDebug() << "m_buttonHoveredFontColor" << "property changed. new value:" << m_buttonHoveredFontColor;
    }
    emit buttonHoveredFontColorChanged(m_buttonHoveredBackgroundColor);
}

void AppSkin::setButtonHoveredBorderColor(const QString& v)
{
    m_buttonHoveredBorderColor = v;
    if(UnicornUIGlobal::self().propertyLoggingEnabled())
    {
        qDebug() << "m_buttonHoveredBorderColor" << "property changed. new value:" << m_buttonHoveredBorderColor;
    }
    emit buttonHoveredBorderColorChanged(m_buttonHoveredBorderColor);
}

void AppSkin::setButtonDisabledBackgroundColor(const QString& v)
{
    m_buttonDisabledBackgroundColor = v;
    if(UnicornUIGlobal::self().propertyLoggingEnabled())
    {
        qDebug() << "m_buttonDisabledBackgroundColor" << "property changed. new value:" << m_buttonDisabledBackgroundColor;
    }
    emit buttonDisabledBackgroundColorChanged(m_buttonDisabledBackgroundColor);
}

void AppSkin::setButtonDisabledFontColor(const QString& v)
{
    m_buttonDisabledFontColor = v;
    if(UnicornUIGlobal::self().propertyLoggingEnabled())
    {
        qDebug() << "m_buttonDisabledFontColor" << "property changed. new value:" << m_buttonDisabledFontColor;
    }
    emit buttonDisabledFontColorChanged(m_buttonDisabledFontColor);
}

void AppSkin::setButtonDisabledBorderColor(const QString& v)
{
    m_buttonDisabledBorderColor = v;
    if(UnicornUIGlobal::self().propertyLoggingEnabled())
    {
        qDebug() << "m_buttonDisabledBorderColor" << "property changed. new value:" << m_buttonDisabledBorderColor;
    }
    emit buttonDisabledBorderColorChanged(m_buttonDisabledBorderColor);
}

void AppSkin::setDefaultMargin(int v)
{
    m_defaultMargin = v;
    if(UnicornUIGlobal::self().propertyLoggingEnabled())
    {
        qDebug() << "m_defaultMargin" << "property changed. new value:" << m_defaultMargin;
    }
    emit defaultMarginChanged(m_defaultMargin);
}

void AppSkin::setDefaultBorderSize(int v)
{
    m_defaultBorderSize = v;
    if(UnicornUIGlobal::self().propertyLoggingEnabled())
    {
        qDebug() << "m_defaultBorderSize" << "property changed. new value:" << m_defaultBorderSize;
    }
    emit defaultBorderSizeChanged(m_defaultBorderSize);
}

void AppSkin::setDefaultBorderRadius(int v)
{
    m_defaultBorderRadius = v;
    if(UnicornUIGlobal::self().propertyLoggingEnabled())
    {
        qDebug() << "m_defaultBorderRadius" << "property changed. new value:" << m_defaultBorderRadius;
    }
    emit defaultBorderRadiusChanged(m_defaultBorderRadius);
}
