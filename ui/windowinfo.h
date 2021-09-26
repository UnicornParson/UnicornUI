#ifndef WINDOWINFO_H
#define WINDOWINFO_H

#include <QObject>

class WindowInfo : public QObject
{
    Q_OBJECT
    Q_PROPERTY(uint Width READ Width WRITE setWidth NOTIFY WidthChanged)
    Q_PROPERTY(uint Height READ Height WRITE setHeight NOTIFY HeightChanged)
    Q_PROPERTY(QString Title READ Title WRITE setTitle NOTIFY TitleChanged)
    Q_PROPERTY(QString Name READ Name WRITE setName NOTIFY NameChanged)
public:
    explicit WindowInfo(QObject *parent = nullptr);
    WindowInfo(uint w, uint h, QObject *parent = nullptr);
    WindowInfo(const WindowInfo& other);
    virtual ~WindowInfo() = default;
    WindowInfo& operator=(const WindowInfo& other);

    uint Width() const;
    uint Height() const;
    QString Title() const;
    QString Name() const;

    Q_INVOKABLE void setWidth(uint v);
    Q_INVOKABLE void setHeight(uint v);
    Q_INVOKABLE void setTitle(QString v);
    Q_INVOKABLE void setName(QString v);

signals:
    void WidthChanged(uint v);
    void HeightChanged(uint v);
    void TitleChanged(QString v);
    void NameChanged(QString v);

protected:
    uint m_Width;
    uint m_Height;
    QString m_Title;
    QString m_Name;
};

#endif // WINDOWINFO_H
