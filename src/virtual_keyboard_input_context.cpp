#include "virtual_keyboard_input_context.h"
#include "virtual_keyboard_context.h"
#include <QGuiApplication>
#include <QFileInfo>
#include <QStandardPaths>
#include <QKeyEvent>
#include <QQmlEngine>
#include <QJSEngine>
#include <pinyinime.h>
#include <QDebug>

VkInputContext::VkInputContext(
    QQmlEngine*,
    QJSEngine*,
    QObject* parent)
    : QObject(parent)
{
    VkPlatformInputContext::instance()
        ->setInputContext(this);
    loadPinyinIME();
}

VkInputContext::~VkInputContext()
{
    unloadPinyinIME();
}

void VkInputContext::showInputPanel()
{
    m_inputPanelVisible = true;
    visibleChanged();
}

void VkInputContext::hideInputPanel()
{
    m_inputPanelVisible = false;
    visibleChanged();
}

bool VkInputContext::isInputPanelVisible()
{
    return m_inputPanelVisible;
}

void VkInputContext::setVisible(bool visible)
{
    if (visible)
    {
        showInputPanel();
    }
    else
    {
        hideInputPanel();
    }
}

void VkInputContext::triggerKeyPressed(
    int key,
    QString text)
{
    if (key == Qt::Key_Backspace)
    {
        auto focusObject = VkPlatformInputContext::instance()
            ->focusObject();
        QKeyEvent event(QEvent::KeyPress,
            key,
            Qt::NoModifier,
            text);
        QGuiApplication::sendEvent(focusObject, &event);
    }

    vkKeyPressed(key);
}

void VkInputContext::triggerKeyReleased(
    int key,
    QString text)
{
    if (key == Qt::Key_Backspace)
    {
        auto focusObject = VkPlatformInputContext::instance()
            ->focusObject();

        QKeyEvent event(QEvent::KeyRelease,
            key,
            Qt::NoModifier,
            text);
        QGuiApplication::sendEvent(focusObject, &event);
    }
}

void VkInputContext::triggerKeyClicked(
    int key,
    QString text)
{
    triggerKeyPressed(key, text);
    triggerKeyReleased(key, text);
}

void VkInputContext::loadPinyinIME()
{
    auto sysDictPath = getSysDictPath("dict_pinyin.dat");
    auto userDictPath = getUserDictPath("dict_pinyin.dat");
    auto ok = ime_pinyin::im_open_decoder(
        sysDictPath.toLocal8Bit(), userDictPath.toLocal8Bit());
    if (ok)
    {
        m_candidatesModel = new QStringListModel();
        candidatesModelChanged();
    }
}

void VkInputContext::unloadPinyinIME()
{
    ime_pinyin::im_close_decoder();
    if (m_candidatesModel)
    {
        m_candidatesModel->deleteLater();
        m_candidatesModel = nullptr;
        candidatesModelChanged();
    }
}

void VkInputContext::vkKeyPressed(int key)
{
    size_t len = 0;
    auto spl = ime_pinyin::im_get_sps_str(&len);
    if (key >= Qt::Key_A && key <= Qt::Key_Z)
    {
        std::string sp;
        if (len > 0)
        {
            sp = spl;
        }
        sp += static_cast<char>(key);
        auto count = ime_pinyin::im_search(sp.c_str(), sp.size());
        updateCandidates(count);
    }
    else if (key == Qt::Key_Backspace)
    {
        std::string sp;
        if (len > 0)
        {
            sp = spl;
        }
        if (sp.size() > 0)
        {
            sp = sp.substr(0, sp.size() - 1);
        }
        auto count = ime_pinyin::im_search(sp.c_str(), sp.size());
        updateCandidates(count);
    }
    else if (key == Qt::Key_Space)
    {
        if (m_candidatesModel && m_candidatesModel->rowCount() > 0)
        {
            selectCandidate(0);
        }
        else
        {
            QKeyEvent event(
                QKeyEvent::KeyPress,
                Qt::Key_Space,
                Qt::NoModifier,
                " ");
            auto focusObject = VkPlatformInputContext::instance()
                ->focusObject();
            QGuiApplication::sendEvent(focusObject, &event);
        }
    }
    else if (key == Qt::Key_Enter)
    {
        QInputMethodEvent event;
        event.setCommitString(QString::fromStdString(spl));
        auto focusObject = VkPlatformInputContext::instance()
            ->focusObject();
        QGuiApplication::sendEvent(focusObject, &event);
    }
}

QStringListModel* VkInputContext::candidatesModel()
{
    return m_candidatesModel;
}

void VkInputContext::clearCandidates()
{
    if (m_candidatesModel)
    {
        m_candidatesModel->setStringList({});
    }
}

void VkInputContext::updateCandidates(size_t count)
{
    if (m_candidatesModel)
    {
        const size_t buffSize = 1024;
        ime_pinyin::char16 buffer[buffSize];
        clearCandidates();
        QStringList candidates;
        for (size_t i = 0; i < count; i++)
        {
            memset(buffer, 0, sizeof(ime_pinyin::char16) * buffSize);
            auto str = ime_pinyin::im_get_candidate(i,
                buffer, buffSize);
            candidates << QString::fromUtf16(str);
        }
        m_candidatesModel->setStringList(candidates);
    }
}

void VkInputContext::selectCandidate(int index)
{
    if (index < 0 || (m_candidatesModel && index > m_candidatesModel->rowCount()))
    {
        return;
    }

    auto count = ime_pinyin::im_choose(static_cast<size_t>(index));
    if (count == 1)
    {
        const size_t bufferSize = 1024;
        ime_pinyin::char16 buffer[bufferSize];
        memset(buffer, 0, sizeof(ime_pinyin::char16) * bufferSize);
        auto str = ime_pinyin::im_get_candidate(0,
            buffer, bufferSize);
        auto focusObject = VkPlatformInputContext::instance()
            ->focusObject();
        QInputMethodEvent event;
        event.setCommitString(QString::fromUtf16(str));
        QGuiApplication::sendEvent(focusObject, &event);
        ime_pinyin::im_reset_search();
        updateCandidates(0);
    }
    else
    {
        updateCandidates(count);
    }
}

QString VkInputContext::getSysDictPath(QString dictName)
{
    auto subfolder = "platforminputcontexts";
    auto appFolder = qGuiApp->applicationDirPath();

    auto folder = appFolder;
    {
        auto file = folder + "/" + subfolder + "/" + dictName;
        if (QFileInfo::exists(file))
        {
            return file;
        }
    }

    return QString();
}

QString VkInputContext::getUserDictPath(QString dictName)
{
    auto folder = QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation);
    return folder + "/" + dictName;
}
