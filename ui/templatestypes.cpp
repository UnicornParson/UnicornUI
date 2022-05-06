#include "templatestypes.h"
#include <QtQml>
TemplatesTypes::TemplatesTypes():
    QObject(nullptr)
{

}

void TemplatesTypes::registerTypes()
{
    qmlRegisterType<ButtonState>("TemplatesTypes", 1, 0, "ButtonState");
    qmlRegisterType<TextType>("TemplatesTypes", 1, 0, "TextType");
    qmlRegisterType<InputState>("TemplatesTypes", 1, 0, "InputState");
    qmlRegisterType<FileAction>("TemplatesTypes", 1, 0, "FileAction");
}
