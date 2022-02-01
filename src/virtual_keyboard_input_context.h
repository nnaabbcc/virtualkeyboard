#pragma once

#include <QObject>

class QQmlEngine;
class QJSEngine;

class VkInputContext : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool visible
        READ isInputPanelVisible
        WRITE setVisible
        NOTIFY visibleChanged);

public:
    VkInputContext(QQmlEngine* engine,
        QJSEngine* scriptEngine,
        QObject* parent = nullptr);
    virtual ~VkInputContext();

    void showInputPanel();
    void hideInputPanel();
    bool isInputPanelVisible();
    void setVisible(bool visible);

    Q_INVOKABLE void triggerKey(
        int key,
        QString text);

Q_SIGNALS:
    void visibleChanged();

private:
    bool m_inputPanelVisible = false;
};
