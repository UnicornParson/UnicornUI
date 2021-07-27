#include "appskin.h"
#include "QStringLiteral"
#include "QString"
#include <QDebug>

#ifndef MAYBE_UNUSED
#define MAYBE_UNUSED [[maybe_unused]]
#endif

#ifndef CONST_LITERAL
#define CONST_LITERAL MAYBE_UNUSED const QString
#endif

#define CHANGE_VARIABLE(name) \
    if(value != m_##name) \
{ \
    m_##name = value; \
    qDebug() << #name << "property changed. new value:" << m_##name; \
    emit name##Changed(m_##name); \
}

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
    qDebug() << "read backgroundColor";
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

void AppSkin::setBackgroundColor(const QString& value)
{
    m_backgroundColor = value;
    qDebug() << "backgroundColor" << "property changed. new value:" << m_backgroundColor;
    emit backgroundColorChanged(m_backgroundColor);
}
void AppSkin::setMainFontColor(const QString& value)
{
    m_mainFontColor = value;
    qDebug() << "m_mainFontColor" << "property changed. new value:" << m_mainFontColor;
    emit mainFontColorChanged(m_mainFontColor);
}

void AppSkin::setButtonBackgroundColor(const QString& value)
{
    m_buttonBackgroundColor = value;
    qDebug() << "m_buttonBackgroundColor" << "property changed. new value:" << m_buttonBackgroundColor;
    emit buttonBackgroundColorChanged(m_buttonBackgroundColor);
}

void AppSkin::setButtonFontColor(const QString& value)
{
    m_buttonFontColor = value;
    qDebug() << "m_buttonFontColor" << "property changed. new value:" << m_buttonFontColor;
    emit buttonFontColorChanged(m_buttonFontColor);
}

void AppSkin::setButtonBorderColor(const QString& value)
{
    m_buttonBorderColor = value;
    qDebug() << "m_buttonBorderColor" << "property changed. new value:" << m_buttonBorderColor;
    emit buttonBorderColorChanged(m_buttonBorderColor);
}

void AppSkin::setButtonHoveredBackgroundColor(const QString& value)
{
    CHANGE_VARIABLE(buttonHoveredBackgroundColor)
}

void AppSkin::setButtonHoveredFontColor(const QString& value)
{
    CHANGE_VARIABLE(buttonHoveredFontColor)
}

void AppSkin::setButtonHoveredBorderColor(const QString& value)
{
    CHANGE_VARIABLE(buttonHoveredBorderColor)
}

void AppSkin::setButtonDisabledBackgroundColor(const QString& value)
{
    CHANGE_VARIABLE(buttonDisabledBackgroundColor)
}

void AppSkin::setButtonDisabledFontColor(const QString& value)
{
    CHANGE_VARIABLE(buttonDisabledFontColor)
}

void AppSkin::setButtonDisabledBorderColor(const QString& value)
{
    CHANGE_VARIABLE(buttonDisabledBorderColor)
}

void AppSkin::setDefaultMargin(int value)
{
    CHANGE_VARIABLE(defaultMargin)
}

void AppSkin::setDefaultBorderSize(int value)
{
    CHANGE_VARIABLE(defaultBorderSize)
}

void AppSkin::setDefaultBorderRadius(int value)
{
    CHANGE_VARIABLE(defaultBorderRadius)
}
