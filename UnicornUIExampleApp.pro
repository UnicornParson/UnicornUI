QT += core gui qml quick quickcontrols2 quicklayouts
TARGET = UnicornUIExample
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
QMAKE_CXXFLAGS_WARN_ON -= -Wreorder -Wformat= -WsignConversion
DEFINES += QT_DEPRECATED_WARNINGS
Release:DESTDIR = bin/release
Release:OBJECTS_DIR = bin/release/.obj
Release:MOC_DIR = bin/release/.moc
Release:RCC_DIR = bin/release/.rcc
Release:UI_DIR = bin/release/.ui

Debug:DESTDIR = bin/debug
Debug:OBJECTS_DIR = bin/debug/.obj
Debug:MOC_DIR = bin/debug/.moc
Debug:RCC_DIR = bin/debug/.rcc
Debug:UI_DIR = bin/debug/.ui
include(ui/UnicornUI.pri)

SOURCES += \
    main.cpp \
    mainwidget.cpp

HEADERS += \
    mainwidget.h

FORMS += \
    mainwidget.ui



RC_ICONS += img/app.ico

RESOURCES += \
    appRc.qrc
