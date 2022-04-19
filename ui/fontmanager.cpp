#include "fontmanager.h"
#include <QMetaEnum>

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
    QMetaEnum e = QMetaEnum::fromType<FontManager::TextType>();
    QStringList countryList;

    for (int k = 0; k < e.keyCount(); ++k)
    {
        TextType tt = TextType(e.value(k));
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

void FontManager::set(const QHash<TextType, QFont>& fonts)
{
    for(auto it = fonts.constKeyValueBegin(); it != fonts.constKeyValueEnd(); ++it)
    {
        m_fonts[it->first] = it->second;
    }
    emit fontsChanged();
}

void FontManager::set(TextType type, const QFont& font)
{
    m_fonts[type] = font;
    emit fontsChanged();
}
