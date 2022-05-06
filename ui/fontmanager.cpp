#include "fontmanager.h"
#include "qfont.h"
#include <QMetaEnum>
#include <QQmlEngine>
namespace
{
static const QFont DefaultFont;
}

FontManager::FontManager(QObject *parent)
    : QObject{parent}
{
    fill();
}

void FontManager::fill()
{
    QMetaEnum e = QMetaEnum::fromType<TextType_t>();
    QStringList countryList;

    for (int k = 0; k < e.keyCount(); ++k)
    {
        TextType_t tt = TextType_t(e.value(k));
        if(m_fonts.contains(tt))
        {
            m_fonts[tt] = DefaultFont;
        }
        else
        {
            m_fonts.insert(tt, DefaultFont);
        }
    }
}

void FontManager::declareQML()
{

}

QFont FontManager::get(TextType_t type) const
{
    return m_fonts.value(type, QFont());
}

void FontManager::set(const QHash<TextType_t, QFont>& fonts)
{
    for(auto it = fonts.constKeyValueBegin(); it != fonts.constKeyValueEnd(); ++it)
    {
        m_fonts[it->first] = it->second;
    }
    emit fontsChanged();
}

void FontManager::set(TextType_t type, const QFont& font)
{
    m_fonts[type] = font;
    emit fontsChanged();
}
