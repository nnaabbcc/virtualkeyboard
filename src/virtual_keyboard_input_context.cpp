#include "virtual_keyboard_input_context.h"
#include "virtual_keyboard_context.h"
#include <QGuiApplication>
#include <QKeyEvent>
#include <QQmlEngine>
#include <QJSEngine>

VkInputContext::VkInputContext(
    QQmlEngine*,
    QJSEngine*,
    QObject* parent)
    : QObject(parent)
{
    VkPlatformInputContext::instance()
        ->setInputContext(this);
}

VkInputContext::~VkInputContext()
{
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
    auto focusObject = VkPlatformInputContext::instance()
        ->focusObject();
    QKeyEvent event(QEvent::KeyPress,
        key,
        Qt::NoModifier,
        text);
    QGuiApplication::sendEvent(focusObject, &event);
}

void VkInputContext::triggerKeyReleased(
    int key,
    QString text)
{
    auto focusObject = VkPlatformInputContext::instance()
        ->focusObject();

    QKeyEvent event(QEvent::KeyRelease,
        key,
        Qt::NoModifier,
        text);
    QGuiApplication::sendEvent(focusObject, &event);
}

void VkInputContext::triggerKeyClicked(
    int key,
    QString text)
{
    triggerKeyPressed(key, text);
    triggerKeyReleased(key, text);
}
