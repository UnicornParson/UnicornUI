#ifndef TEMPLATESTYPES_H
#define TEMPLATESTYPES_H

#include <QObject>

class ButtonState : public QObject
{
    Q_OBJECT
public:
    enum e {
        Normal,
        Disabled,
        Active,
        Hovered
    };
    Q_ENUM(e)
};

class TemplatesTypes : public QObject
{
    Q_OBJECT
public:
    TemplatesTypes();
    static void registerTypes();
signals:

public slots:
};

#endif // TEMPLATESTYPES_H
