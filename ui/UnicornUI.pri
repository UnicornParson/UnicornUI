INCLUDEPATH += $$PWD
QT += quickcontrols2 quick qml
QML_IMPORT_TRACE=1
SOURCES += \
    $$PWD/fontmanager.cpp \
    $$PWD/templatestypes.cpp \
    $$PWD/qmlbootstrapper.cpp \
    $$PWD/appskin.cpp \
    $$PWD/unicornuiglobal.cpp \
    $$PWD/windowcontroller.cpp \
    $$PWD/windowinfo.cpp

HEADERS += \
    $$PWD/fontmanager.h \
    $$PWD/templatestypes.h \
    $$PWD/qmlbootstrapper.h \
    $$PWD/appskin.h \
    $$PWD/unicornuiglobal.h \
    $$PWD/windowcontroller.h \
    $$PWD/windowinfo.h

QML2_IMPORT_PATH += $$PWD/qml
QML_IMPORT_PATH += $$PWD/qml
CONFIG+=qml_debug

OTHER_FILES += \
    $$PWD/*.qml \
    $$PWD/qml/*

RESOURCES += \
    $$PWD/templates.qrc

#requiredData.path = $${DESTDIR}
#requiredData.files +=$$PWD/*.qml
#requiredData.files +=$$PWD/qml
#requiredData.files +=$$PWD/qml/*
#INSTALLS += requiredData

