#include "templatestypes.h"
#include <QtQml>
TemplatesTypes::TemplatesTypes():
    QObject(nullptr)
{

}

void TemplatesTypes::registerTypes()
{
    qmlRegisterType<ButtonState>("TemplatesTypes", 1, 0, "ButtonState");
}
