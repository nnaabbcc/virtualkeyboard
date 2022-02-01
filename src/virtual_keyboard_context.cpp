#include "virtual_keyboard_context.h"
#include <QRectF>
#include <QLocale>

VirtualKeyboardInputContext::VirtualKeyboardInputContext()
{}

VirtualKeyboardInputContext::~VirtualKeyboardInputContext()
{}

bool VirtualKeyboardInputContext::isValid() const
{
    // return QPlatformInputContext::isValid();
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
    QPlatformInputContext::showInputPanel();
}

void VirtualKeyboardInputContext::hideInputPanel()
{
    QPlatformInputContext::hideInputPanel();
}

bool VirtualKeyboardInputContext::isInputPanelVisible() const
{
    return QPlatformInputContext::isInputPanelVisible();
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
    QPlatformInputContext::setFocusObject(object);
}
