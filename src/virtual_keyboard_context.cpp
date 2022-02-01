#include "virtual_keyboard_context.h"
#include <QRectF>
#include <QLocale>
#include <QGuiApplication>
#include <QApplication>
#include <QDebug>

VirtualKeyboardInputContext::VirtualKeyboardInputContext()
    : m_inputPanel(nullptr)
{}

VirtualKeyboardInputContext::~VirtualKeyboardInputContext()
{
    hideInputPanel();
    if (m_inputPanel)
    {
        m_inputPanel->deleteLater();
    }
}

bool VirtualKeyboardInputContext::isValid() const
{
    return true;
}

bool VirtualKeyboardInputContext::hasCapability(
    Capability capability
) const
{
    return QPlatformInputContext::hasCapability(capability);
}

void VirtualKeyboardInputContext::reset()
{
    QPlatformInputContext::reset();
}

void VirtualKeyboardInputContext::commit()
{
    QPlatformInputContext::commit();
}

void VirtualKeyboardInputContext::update(
    Qt::InputMethodQueries querys)
{
    QPlatformInputContext::update(querys);
}

void VirtualKeyboardInputContext::invokeAction(
    QInputMethod::Action action,
    int cursorPosition)
{
    QPlatformInputContext::invokeAction(
        action, cursorPosition);
}

bool VirtualKeyboardInputContext::filterEvent(
    const QEvent* event)
{
    return QPlatformInputContext::filterEvent(event);
}

QRectF VirtualKeyboardInputContext::keyboardRect() const
{
    return QPlatformInputContext::keyboardRect();
}

bool VirtualKeyboardInputContext::isAnimating() const
{
    return QPlatformInputContext::isAnimating();
}

void VirtualKeyboardInputContext::showInputPanel()
{
    if (m_inputPanel == nullptr)
    {
        m_inputPanel = new VkInputPanel();
        QObject::connect(m_inputPanel,
            &VkInputPanel::emitEvent,
            this,
            &VirtualKeyboardInputContext::slotInputEvent);
    }
    m_inputPanel->show();
}

void VirtualKeyboardInputContext::hideInputPanel()
{
    if (m_inputPanel)
    {
        m_inputPanel->hide();
    }
}

bool VirtualKeyboardInputContext::isInputPanelVisible() const
{
    if (m_inputPanel)
    {
        return m_inputPanel->isVisible();
    }
    return false;
}

QLocale VirtualKeyboardInputContext::locale() const
{
    return QPlatformInputContext::locale();
}

Qt::LayoutDirection VirtualKeyboardInputContext::inputDirection() const
{
    return QPlatformInputContext::inputDirection();
}

void VirtualKeyboardInputContext::setFocusObject(QObject* object)
{
    m_focusObject = object;
}

void VirtualKeyboardInputContext::slotInputEvent(
    QEvent* event)
{
    if (m_focusObject)
    {
        QGuiApplication::sendEvent(
            m_focusObject,
            event);
    }
}
