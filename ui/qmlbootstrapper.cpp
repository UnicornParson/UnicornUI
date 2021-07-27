#include "qmlbootstrapper.h"
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

const QString PlaceholderRoot("qml/fakeRoot.qml");
const QString MainImportPath("qrc:/");
const QStringList AdditionalImports =
{
    ".",
    "qml",
    "qml/UnicornUI",
    "qml/UnicornUI/qmldir",
    ":/qml/UnicornUI",
    ":/qml/",
    ":/",
};

QmlBootstrapper::QmlBootstrapper(QObject *parent) :
    QObject(parent),
    m_skin(this),
    m_winInfo(this),
    m_qmlEngine(nullptr),
    m_rootPath(PlaceholderRoot)
{
    m_winInfo.setHeight(600);
    m_winInfo.setWidth(800);
    m_winInfo.setTitle("WinTitle");
}

QmlBootstrapper::~QmlBootstrapper()
{
    destroyEngine();
}

QString QmlBootstrapper::rootPath() const
{
    return m_rootPath;
}

void QmlBootstrapper::setRoot(const QString& path)
{
    if (m_rootPath != path)
    {
        qDebug() << "qml root page updated " << m_rootPath << " -> " << path;
        m_rootPath = path;
        emit rootChanged(m_rootPath);
    }
}

void QmlBootstrapper::createEngine()
{
    qDebug() << "create qml engine";
    if(m_qmlEngine != nullptr)
    {
        qWarning() << "qml engine alreade exists";
        destroyEngine();
    }
    m_qmlEngine = new QQmlApplicationEngine(this);
    connect(m_qmlEngine, &QQmlApplicationEngine::warnings, this, &QmlBootstrapper::onQmlWarnings);
    connect(m_qmlEngine, &QQmlApplicationEngine::quit, this, &QmlBootstrapper::onQuit);
    connect(m_qmlEngine, &QQmlApplicationEngine::exit, this, &QmlBootstrapper::onExit);
}

void QmlBootstrapper::destroyEngine()
{
    qDebug() << "destroy qml engine";
    if(m_qmlEngine != nullptr)
    {
        disconnect(m_qmlEngine, &QQmlApplicationEngine::warnings, this, &QmlBootstrapper::onQmlWarnings);
        m_qmlEngine->deleteLater();
        m_qmlEngine = nullptr;
    }
}


bool QmlBootstrapper::start()
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

void QmlBootstrapper::onQuit()
{
    qDebug() << "onQuit";
    emit quit();
}

void QmlBootstrapper::onExit(int retCode)
{
    qDebug() << "onQuit" << retCode;
    emit exit(retCode);
}

void QmlBootstrapper::onQmlWarnings(const QList<QQmlError> &warnings)
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
