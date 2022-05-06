#ifndef TEMPLATESTYPES_H
#define TEMPLATESTYPES_H

#include "qglobal.h"
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
    Q_DISABLE_COPY_MOVE(ButtonState)
    ButtonState() = delete;
};

class FileAction : public QObject
{
    Q_OBJECT
public:
    enum e {
        Open,
        Save
    };
    Q_ENUM(e)
    Q_DISABLE_COPY_MOVE(FileAction)
    FileAction() = delete;
};


class InputState : public QObject
{
    Q_OBJECT
public:
    enum e {
        Normal,
        Disabled,
        Active,
        Hovered,
        Error
    };
    Q_ENUM(e)
    Q_DISABLE_COPY_MOVE(InputState)
    InputState() = delete;
};

class TextType : public QObject
{
    Q_OBJECT
public:
    enum e {
        Title,
        Subtitile,
        Header,
        H1,H2,H3,H4,H5,H6,H7,
        Normal,
        Highlighted,
        Custom
    };
    Q_ENUM(e)
    Q_DISABLE_COPY_MOVE(TextType)
    TextType() = delete;
};

using TextType_t = TextType::e;
using ButtonState_t = ButtonState::e;
using InputState_t = InputState::e;
using FileAction_t = FileAction::e;

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
