#ifndef FONTMANAGER_H
#define FONTMANAGER_H

#include "qfont.h"
#include <QObject>
#include <QHash>
#include <QFont>

class FontManager : public QObject
{
    Q_OBJECT
public:
    explicit FontManager(QObject *parent = nullptr);
    enum class TextType
    {
        Title,
        Subtitile,
        Header,
        H1,H2,H3,H4,H5,H6,H7,
        Normal,
        Highlighted
    };
    Q_ENUM(TextType)

    QFont get(TextType type) const;
    void set(TextType type, const QFont& font);
    void set(const QHash<TextType, QFont>& fonts);
signals:
    void fontsChanged();
protected:
    virtual void fill();
    QHash<TextType, QFont> m_fonts;
};

#endif // FONTMANAGER_H
