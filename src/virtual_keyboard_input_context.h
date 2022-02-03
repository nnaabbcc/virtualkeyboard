#pragma once

#include <QObject>
#include <QStringListModel>

class QQmlEngine;
class QJSEngine;

class VkInputContext : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool visible
        READ isInputPanelVisible
        WRITE setVisible
        NOTIFY visibleChanged);

    Q_PROPERTY(QStringListModel* candidatesModel
        READ candidatesModel
        NOTIFY candidatesModelChanged);

public:
    VkInputContext(QQmlEngine* engine,
        QJSEngine* scriptEngine,
        QObject* parent = nullptr);
    virtual ~VkInputContext();

    void showInputPanel();
    void hideInputPanel();
    bool isInputPanelVisible();
    void setVisible(bool visible);

    Q_INVOKABLE void triggerKeyPressed(
        int key,
        QString text);
    Q_INVOKABLE void triggerKeyReleased(
        int key,
        QString text);
    Q_INVOKABLE void triggerKeyClicked(
        int key,
        QString text);
    Q_INVOKABLE void selectCandidate(int index);

    QStringListModel* candidatesModel();

private:
    void loadPinyinIME();
    void unloadPinyinIME();
    void vkKeyPressed(int key);
    void updateCandidates(size_t count);
    void clearCandidates();

    QString getSysDictPath(QString dictName);
    QString getUserDictPath(QString dictName);

Q_SIGNALS:
    void visibleChanged();
    void candidatesModelChanged();

private:
    bool m_inputPanelVisible = false;
    QStringListModel* m_candidatesModel = nullptr;
};
