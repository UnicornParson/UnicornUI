#include "appskin.h"
#include "QStringLiteral"
#include "QString"
#include <QDebug>
#include "fontmanager.h"
#include "qobject.h"
#include "unicornuiglobal.h"


namespace DefaultSkin
{
CONST_LITERAL DefaultBackgroundColor("white");
CONST_LITERAL DefaultSecondBackgroundColor("#C5D3E2");

CONST_LITERAL DefaultFirstBorderColor("#303030");
CONST_LITERAL DefaultSecondBorderColor("#1C2A39");

CONST_LITERAL DefaultFontColor("black");
CONST_LITERAL DefaultDisabledFontColor("gainsboro");
CONST_LITERAL DefaultButtonBackgroundColor("#C5D3E2");
CONST_LITERAL DefaultButtonFontColor("#5C6A79");
CONST_LITERAL DefaultButtonBorderColor("#5C6A79");
CONST_LITERAL DefaultButtonHoveredBackgroundColor("#5C6A79");
CONST_LITERAL DefaultButtonHoveredFontColor("#C5D3E2");
CONST_LITERAL DefaultButtonHoveredBorderColor("#C5D3E2");
CONST_LITERAL DefaultButtonDisabledBackgroundColor("#E0E0E0");
CONST_LITERAL DefaultButtonDisabledFontColor("#D0D0D0");
CONST_LITERAL DefaultButtonDisabledBorderColor("#D0D0D0");
CONST_LITERAL DefaultAccentColor("#303030");

constexpr int DefaultMargin = 2;
constexpr int DefaultBorderSize = 1;
constexpr int DefaultBorderRadius = 5;
}

AppSkin::AppSkin(QObject *parent) :
    QObject(parent),
    m_backgroundColor(DefaultSkin::DefaultBackgroundColor),
    m_secondBackgroundColor(DefaultSkin::DefaultSecondBackgroundColor),
    m_mainFontColor(DefaultSkin::DefaultFontColor),
    m_mainDisabledFontColor(DefaultSkin::DefaultDisabledFontColor),
    m_buttonBackgroundColor(DefaultSkin::DefaultButtonBackgroundColor),
    m_buttonFontColor(DefaultSkin::DefaultButtonFontColor),
    m_buttonBorderColor(DefaultSkin::DefaultButtonBorderColor),
    m_buttonHoveredBackgroundColor(DefaultSkin::DefaultButtonHoveredBackgroundColor),
    m_buttonHoveredFontColor(DefaultSkin::DefaultButtonHoveredFontColor),
    m_buttonHoveredBorderColor(DefaultSkin::DefaultButtonHoveredBorderColor),
    m_buttonDisabledBackgroundColor(DefaultSkin::DefaultButtonDisabledBackgroundColor),
    m_buttonDisabledFontColor(DefaultSkin::DefaultButtonDisabledFontColor),
    m_buttonDisabledBorderColor(DefaultSkin::DefaultButtonDisabledBorderColor),
    m_firstBorderColor(DefaultSkin::DefaultFirstBorderColor),
    m_secondBorderColor(DefaultSkin::DefaultSecondBorderColor),
    m_accentColor(DefaultSkin::DefaultAccentColor),
    m_defaultMargin(DefaultSkin::DefaultMargin),
    m_defaultBorderSize(DefaultSkin::DefaultBorderSize),
    m_defaultBorderRadius(DefaultSkin::DefaultBorderRadius),
  m_fontManager(this)
{

}

void AppSkin::declareQML()
{

}

bool AppSkin::loadFromFile(const QString& path)
{
    Q_UNUSED(path)
    // TODO: json loader
    return false;
}

bool AppSkin::loadFromMap(const QMap<SkinKey, QString>& map)
{
    bool ret = true;
    for (auto it = map.constKeyValueBegin(); it != map.constKeyValueEnd(); ++it)
    {
        const QString& val = it->second;
        switch(it->first)
        {
        case SkinKey::BackgroundColor: {setBackgroundColor(val);break;}
        case SkinKey::SecondBackgroundColor: {setSecondBackgroundColor(val);break;}
        case SkinKey::FirstBorderColor: {setFirstBorderColor(val);break;}
        case SkinKey::DisabledFontColor: {mainDisabledFontColorChanged(val);break;}

        case SkinKey::SecondBorderColor: {setSecondBorderColor(val);break;}
        case SkinKey::FontColor: {setMainFontColor(val);break;}
        case SkinKey::ButtonBackgroundColor: {setButtonBackgroundColor(val);break;}
        case SkinKey::ButtonFontColor: {setButtonFontColor(val);break;}
        case SkinKey::ButtonBorderColor: {setButtonBorderColor(val);break;}
        case SkinKey::ButtonHoveredBackgroundColor: {setButtonHoveredBackgroundColor(val);break;}
        case SkinKey::ButtonHoveredFontColor: {setButtonHoveredFontColor(val);break;}
        case SkinKey::ButtonHoveredBorderColor: {setButtonHoveredBorderColor(val);break;}
        case SkinKey::ButtonDisabledBackgroundColor: {setButtonDisabledBackgroundColor(val);break;}
        case SkinKey::ButtonDisabledFontColor: {setButtonDisabledFontColor(val);break;}
        case SkinKey::ButtonDisabledBorderColor: {setButtonDisabledBorderColor(val);break;}
        case SkinKey::Margin: {setDefaultMargin(val.toInt(&ret));break;}
        case SkinKey::BorderSize: {setDefaultBorderSize(val.toInt(&ret));break;}
        case SkinKey::BorderRadius: {setDefaultBorderRadius(val.toInt(&ret));break;}
        case SkinKey::AccentColor: {setAccentColor(val);break;}
        }
    }
    return ret;
}

QObject* AppSkin::fonts()
{
    return qobject_cast<QObject*>(&m_fontManager);
}

FontManager& AppSkin::fontManager()
{
    return m_fontManager;
}

QString AppSkin::backgroundColor() const
{
    return m_backgroundColor;
}

QString AppSkin::secondBackgroundColor() const
{
    return m_secondBackgroundColor;
}

QString AppSkin::mainFontColor() const
{
    return m_mainFontColor;
}

QString AppSkin::mainDisabledFontColor() const
{
    return m_mainDisabledFontColor;
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

QString AppSkin::firstBorderColor() const
{
    return m_firstBorderColor;
}

QString AppSkin::secondBorderColor() const
{
    return m_secondBorderColor;
}

QString AppSkin::accentColor() const
{
    return m_accentColor;
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

void AppSkin::setSecondBackgroundColor(const QString& v)
{
    m_secondBackgroundColor = v;
    if(UnicornUIGlobal::self().propertyLoggingEnabled())
    {
        qDebug() << "m_secondBackgroundColor" << "property changed. new value:" << m_secondBackgroundColor;
    }
    emit secondBackgroundColorChanged(m_secondBackgroundColor);
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

void AppSkin::setMainDisabledFontColor(const QString& v)
{
    m_mainDisabledFontColor = v;
    if(UnicornUIGlobal::self().propertyLoggingEnabled())
    {
        qDebug() << "m_mainDisabledFontColor" << "property changed. new value:" << m_mainDisabledFontColor;
    }
    emit mainDisabledFontColorChanged(m_mainFontColor);
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

void AppSkin::setFirstBorderColor(const QString& v)
{
    m_firstBorderColor = v;
    if(UnicornUIGlobal::self().propertyLoggingEnabled())
    {
        qDebug() << "m_firstBorderColor" << "property changed. new value:" << m_firstBorderColor;
    }
    emit firstBorderColorChanged(m_firstBorderColor);
}

void AppSkin::setAccentColor(const QString& v)
{
    m_accentColor = v;
    if(UnicornUIGlobal::self().propertyLoggingEnabled())
    {
        qDebug() << "m_accentColor" << "property changed. new value:" << m_accentColor;
    }
    emit accentColorChanged(m_accentColor);
}

void AppSkin::setSecondBorderColor(const QString& v)
{
    m_secondBorderColor = v;
    if(UnicornUIGlobal::self().propertyLoggingEnabled())
    {
        qDebug() << "m_secondBorderColor" << "property changed. new value:" << m_secondBorderColor;
    }
    emit secondBorderColorChanged(m_secondBorderColor);
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
