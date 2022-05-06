#ifndef FONTMANAGER_H
#define FONTMANAGER_H

#include "qfont.h"
#include "qtmetamacros.h"
#include "templatestypes.h"
#include <QObject>
#include <QHash>
#include <QFont>

class FontManager : public QObject
{
    Q_OBJECT
public:
    explicit FontManager(QObject *parent = nullptr);

    Q_INVOKABLE QFont get(TextType_t type) const;
    Q_INVOKABLE void set(TextType_t type, const QFont& font);
    Q_INVOKABLE void set(const QHash<TextType_t, QFont>& fonts);
    static void declareQML();
signals:
    void fontsChanged();
protected:
    virtual void fill();
    QHash<TextType_t, QFont> m_fonts;
};

#endif // FONTMANAGER_H
