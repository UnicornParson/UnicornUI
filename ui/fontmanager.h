#ifndef FONTMANAGER_H
#define FONTMANAGER_H

#include "qfont.h"
#include "qtmetamacros.h"
#include <QObject>
#include <QHash>
#include <QFont>

class FontManager : public QObject
{
    Q_OBJECT
public:
    explicit FontManager(QObject *parent = nullptr);
    enum TextType
    {
        Title,
        Subtitile,
        Header,
        H1,H2,H3,H4,H5,H6,H7,
        Normal,
        Highlighted,
        Custom
    };
    Q_ENUM(TextType)

    Q_INVOKABLE QFont get(TextType type) const;
    Q_INVOKABLE void set(TextType type, const QFont& font);
    Q_INVOKABLE void set(const QHash<TextType, QFont>& fonts);
    static void declareQML();
signals:
    void fontsChanged();
protected:
    virtual void fill();
    QHash<TextType, QFont> m_fonts;
};

#endif // FONTMANAGER_H
