#include "windowcontroller.h"
#include <QtGui/QScreen>
#include <QtQml/QQmlEngine>
#include <QtQml/QQmlContext>
#include <QtQml/QQmlComponent>
#include <QStringLiteral>
#include <QtQuick/QQuickWindow>
#include <QtCore/QUrl>
#include <QDebug>
#include <QFile>
#include <QDir>
#include "templatestypes.h"
#include "windowcontroller.h"
#include "unicornuiglobal.h"

namespace
{
[[maybe_unused]] const QString MainImportPath("qrc:/");
[[maybe_unused]] const QStringList AdditionalImports =
{
    ".",
    "qml",
    "qml/UnicornUI",
    "qml/UnicornUI/qmldir",
    ":/qml/UnicornUI",
    ":/qml/",
    ":/",
    "qrc:///",
    "qrc:///qml",
    "qrc:///qml/UnicornUI"
};
[[maybe_unused]] constexpr int defaultWidth(800);
[[maybe_unused]] constexpr int defaultHeight(600);
}

WindowController::WindowController(QObject *parent) :
    QObject(parent),
    m_qmlEngine(nullptr)
{
    m_winInfo.setWidth(defaultWidth);
    m_winInfo.setHeight(defaultHeight);
    connect(&m_winInfo, &WindowInfo::WidthChanged, [this](int w){if(w <= 0){m_winInfo.setWidth(defaultWidth);}});
    connect(&m_winInfo, &WindowInfo::HeightChanged, [this](int h){if(h <= 0){m_winInfo.setHeight(defaultHeight);}});
}

QString WindowController::rootPath() const
{
    return m_rootPath;
}

void WindowController::setRoot(const QString& path)
{
    if (m_rootPath != path)
    {
        qDebug() << "qml root page updated " << m_rootPath << " -> " << path;
        m_rootPath = path;
        emit rootChanged(m_rootPath);
    }
}

AppSkin& WindowController::skin()
{
    return m_skin;
}

bool WindowController::start()
{
    bool ret = false;
    QFile f(m_rootPath);
    do
    {
        bool openRc = f.open(QIODevice::ReadOnly);
        if(!openRc)
        {
            qWarning() << "cannot open file " << m_rootPath;
        }
        createEngine();
        QDir d(MainImportPath);
        qWarning() << MainImportPath << "contains" << d.entryList();
        QQuickWindow::setDefaultAlphaBuffer(true);
        m_qmlEngine->rootContext()->setContextProperty("skin", &m_skin);
        m_qmlEngine->rootContext()->setContextProperty("wininfo", &m_winInfo);
        m_qmlEngine->rootContext()->setContextProperty("globals", &UnicornUIGlobal::self());
        m_qmlEngine->addImportPath(MainImportPath);
        for (const QString& s: AdditionalImports)
        {
            m_qmlEngine->addImportPath(s);
        }
        m_qmlEngine->addImportPath( QStringLiteral("/qml"));
        m_qmlEngine->addImportPath( QStringLiteral("/qml/QtQuick"));
        m_qmlEngine->addImportPath( QStringLiteral("/qml/QtQuick/Controls"));
        qDebug() << "import from " << m_qmlEngine->importPathList();
        TemplatesTypes::registerTypes();

        qDebug() << "load root from " << m_rootPath;
        connect(m_qmlEngine, &QQmlApplicationEngine::objectCreated, [](QObject *object, const QUrl &url)
        {
            Q_UNUSED(object)
            qWarning() << "objectCreated" << url;
        });

        m_qmlEngine->load(m_rootPath);
        ret = true;
    }
    while(false);
    if(f.isOpen())
    {
        f.close();
    }
    return ret;
}

void WindowController::createEngine()
{
    qDebug() << "create qml engine";
    if(m_qmlEngine != nullptr)
    {
        qWarning() << "qml engine alreade exists";
        destroyEngine();
    }
    m_qmlEngine = new QQmlApplicationEngine(this);
    connect(m_qmlEngine, &QQmlApplicationEngine::warnings, this, &WindowController::onQmlWarnings);
    connect(m_qmlEngine, &QQmlApplicationEngine::quit, this, &WindowController::onQuit);
    connect(m_qmlEngine, &QQmlApplicationEngine::exit, this, &WindowController::onExit);
}

int WindowController::width() const
{
    return m_winInfo.Width();
}

int WindowController::height() const
{
    return m_winInfo.Height();
}

QString WindowController::title() const
{
    return m_winInfo.Title();
}

void WindowController::destroyEngine()
{
    qDebug() << "destroy qml engine";
    if(m_qmlEngine != nullptr)
    {
        disconnect(m_qmlEngine, &QQmlApplicationEngine::warnings, this, &WindowController::onQmlWarnings);
        m_qmlEngine->deleteLater();
        m_qmlEngine = nullptr;
    }
}

QObject* WindowController::wininfoobj()
{
    return &m_winInfo;
}

WindowInfo& WindowController::info()
{
    return m_winInfo;
}

void WindowController::onQuit()
{
    qDebug() << "onQuit";
    emit quit();
}

void WindowController::onExit(int retCode)
{
    qDebug() << "onQuit" << retCode;
    emit exit(retCode);
}

void WindowController::onQmlWarnings(const QList<QQmlError> &warnings)
{
    for (const QQmlError& e: warnings)
    {
        qWarning() << QString("QMl warning in %1 line %2, column %3 %4")
                      .arg(e.url().toString())
                      .arg(e.line())
                      .arg(e.column())
                      .arg(e.description());
    }
}

QVariant WindowController::contextProperty(const QString &name) const
{
    m_qmlEngine->rootContext()->contextProperty(name);
}

void WindowController::setContextProperty(const QString &name, QObject *obj)
{
    m_qmlEngine->rootContext()->setContextProperty(name, obj);
}

void WindowController::setContextProperty(const QString &name, const QVariant &v)
{
    m_qmlEngine->rootContext()->setContextProperty(name, v);
}
