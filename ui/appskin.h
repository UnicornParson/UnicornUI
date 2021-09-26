#ifndef APPSKIN_H
#define APPSKIN_H

#include <QObject>

//TODO: move to toolib qml library

class AppSkin : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString backgroundColor READ backgroundColor NOTIFY backgroundColorChanged)
    Q_PROPERTY(QString mainFontColor READ mainFontColor NOTIFY mainFontColorChanged)

    Q_PROPERTY(QString buttonBackgroundColor READ buttonBackgroundColor NOTIFY buttonBackgroundColorChanged)
    Q_PROPERTY(QString buttonFontColor READ buttonFontColor NOTIFY buttonFontColorChanged)
    Q_PROPERTY(QString buttonBorderColor READ buttonBorderColor NOTIFY buttonBorderColorChanged)

    Q_PROPERTY(QString buttonHoveredBackgroundColor READ buttonHoveredBackgroundColor NOTIFY buttonHoveredBackgroundColorChanged)
    Q_PROPERTY(QString buttonHoveredFontColor READ buttonHoveredFontColor NOTIFY buttonHoveredFontColorChanged)
    Q_PROPERTY(QString buttonHoveredBorderColor READ buttonHoveredBorderColor NOTIFY buttonHoveredBorderColorChanged)

    Q_PROPERTY(QString buttonDisabledBackgroundColor READ buttonDisabledBackgroundColor NOTIFY buttonDisabledBackgroundColorChanged)
    Q_PROPERTY(QString buttonDisabledFontColor READ buttonDisabledFontColor NOTIFY buttonDisabledFontColorChanged)
    Q_PROPERTY(QString buttonDisabledBorderColor READ buttonDisabledBorderColor NOTIFY buttonDisabledBorderColorChanged)

    Q_PROPERTY(int defaultMargin READ defaultMargin NOTIFY defaultMarginChanged)
    Q_PROPERTY(int defaultBorderSize READ defaultBorderSize NOTIFY defaultBorderSizeChanged)
    Q_PROPERTY(int defaultBorderRadius READ defaultBorderRadius NOTIFY defaultBorderRadiusChanged)

public:
    explicit AppSkin(QObject *parent = nullptr);
    bool loadFromFile(const QString& path);

    // getters
    QString backgroundColor() const;
    QString mainFontColor() const;
    QString buttonBackgroundColor() const;
    QString buttonFontColor() const;
    QString buttonBorderColor() const;
    QString buttonHoveredBackgroundColor() const;
    QString buttonHoveredFontColor() const;
    QString buttonHoveredBorderColor() const;
    QString buttonDisabledBackgroundColor() const;
    QString buttonDisabledFontColor() const;
    QString buttonDisabledBorderColor() const;
    int defaultMargin() const;
    int defaultBorderSize() const;
    int defaultBorderRadius() const;

signals:
    void backgroundColorChanged(const QString& value);
    void mainFontColorChanged(const QString& value);
    void buttonBackgroundColorChanged(const QString& value);
    void buttonFontColorChanged(const QString& value);
    void buttonBorderColorChanged(const QString& value);
    void buttonHoveredBackgroundColorChanged(const QString& value);
    void buttonHoveredFontColorChanged(const QString& value);
    void buttonHoveredBorderColorChanged(const QString& value);
    void buttonDisabledBackgroundColorChanged(const QString& value);
    void buttonDisabledFontColorChanged(const QString& value);
    void buttonDisabledBorderColorChanged(const QString& value);
    void defaultMarginChanged(int value);
    void defaultBorderSizeChanged(int value);
    void defaultBorderRadiusChanged(int value);

private:
    // private setters
    void setBackgroundColor(const QString& v);
    void setMainFontColor(const QString& v);
    void setButtonBackgroundColor(const QString& v);
    void setButtonFontColor(const QString& v);
    void setButtonBorderColor(const QString& v);
    void setButtonHoveredBackgroundColor(const QString& v);
    void setButtonHoveredFontColor(const QString& v);
    void setButtonHoveredBorderColor(const QString& v);
    void setButtonDisabledBackgroundColor(const QString& v);
    void setButtonDisabledFontColor(const QString& v);
    void setButtonDisabledBorderColor(const QString& v);
    void setDefaultMargin(int value);
    void setDefaultBorderSize(int value);
    void setDefaultBorderRadius(int value);

    QString m_backgroundColor;
    QString m_mainFontColor;
    QString m_buttonBackgroundColor;
    QString m_buttonFontColor;
    QString m_buttonBorderColor;
    QString m_buttonHoveredBackgroundColor;
    QString m_buttonHoveredFontColor;
    QString m_buttonHoveredBorderColor;
    QString m_buttonDisabledBackgroundColor;
    QString m_buttonDisabledFontColor;
    QString m_buttonDisabledBorderColor;
    int m_defaultMargin;
    int m_defaultBorderSize;
    int m_defaultBorderRadius;

}; // class AppSkin

#endif // APPSKIN_H
