#include "virtual_keyboard_context.h"
#include "virtual_keyboard_input_context.h"
#include "virtual_keyboard_input_panel.h"
#include <QRectF>
#include <QLocale>
#include <QGuiApplication>

static VkPlatformInputContext* gPlatformInputContext = nullptr;

VkPlatformInputContext* VkPlatformInputContext::instance()
{
    if (gPlatformInputContext == nullptr)
    {
        VkPlatformInputContext::create();
    }
    return gPlatformInputContext;
}

VkPlatformInputContext* VkPlatformInputContext::create()
{
    if (gPlatformInputContext == nullptr)
    {
        gPlatformInputContext = new VkPlatformInputContext();
    }
    return gPlatformInputContext;
}

void VkPlatformInputContext::destory()
{
    if (gPlatformInputContext != nullptr)
    {
        gPlatformInputContext->deleteLater();
        gPlatformInputContext = nullptr;
    }
}

VkPlatformInputContext::VkPlatformInputContext()
    : m_inputContext(nullptr)
    , m_inputPanel(nullptr)
{}

VkPlatformInputContext::~VkPlatformInputContext()
{
    if (m_inputPanel)
    {
        m_inputPanel->deleteLater();
    }
}

bool VkPlatformInputContext::isValid() const
{
    return true;
}

bool VkPlatformInputContext::hasCapability(
    Capability capability) const
{
    return QPlatformInputContext::hasCapability(capability);
}

void VkPlatformInputContext::reset()
{
    QPlatformInputContext::reset();
}

void VkPlatformInputContext::commit()
{
    QPlatformInputContext::commit();
}

void VkPlatformInputContext::update(
    Qt::InputMethodQueries querys)
{
    Q_UNUSED(querys);

    if (m_inputContext)
    {
        auto enabled = inputMethodQuery(Qt::ImEnabled).toBool();
        if (!enabled)
        {
            hideInputPanel();
        }
    }
}

QVariant VkPlatformInputContext::inputMethodQuery(
    Qt::InputMethodQuery query)
{
    QInputMethodQueryEvent event(query);
    if (m_focusObject)
    {
        QGuiApplication::sendEvent(m_focusObject, &event);
    }
    return event.value(query);
}

void VkPlatformInputContext::invokeAction(
    QInputMethod::Action action,
    int cursorPosition)
{
    QPlatformInputContext::invokeAction(
        action, cursorPosition);
}

bool VkPlatformInputContext::filterEvent(
    const QEvent* event)
{
    return QPlatformInputContext::filterEvent(event);
}

QRectF VkPlatformInputContext::keyboardRect() const
{
    return QPlatformInputContext::keyboardRect();
}

bool VkPlatformInputContext::isAnimating() const
{
    return QPlatformInputContext::isAnimating();
}

void VkPlatformInputContext::showInputPanel()
{
    // No Input Context instance created, let's provide a one
    // in a floating quick window, we provide Input Context by
    // through input panel
    if (m_inputContext == nullptr)
    {
        m_inputPanel = new VkInputPanel();
    }

    if (m_inputContext)
    {
        m_inputContext->showInputPanel();
    }

    emitInputPanelVisibleChanged();
}

void VkPlatformInputContext::hideInputPanel()
{
    if (m_inputContext)
    {
        m_inputContext->hideInputPanel();
    }

    emitInputPanelVisibleChanged();
}

bool VkPlatformInputContext::isInputPanelVisible() const
{
    if (m_inputContext)
    {
        return m_inputContext->isInputPanelVisible();
    }
    return false;
}

QLocale VkPlatformInputContext::locale() const
{
    return QPlatformInputContext::locale();
}

Qt::LayoutDirection VkPlatformInputContext::inputDirection() const
{
    return QPlatformInputContext::inputDirection();
}

void VkPlatformInputContext::setFocusObject(QObject* object)
{
    m_focusObject = object;
    update(Qt::ImQueryAll);
}

QObject* VkPlatformInputContext::focusObject()
{
    return m_focusObject;
}

void VkPlatformInputContext::setInputContext(
    VkInputContext* context)
{
    if (m_inputContext == context)
    {
        return;
    }

    if (m_inputContext)
    {
        disconnect(m_inputContext, &VkInputContext::visibleChanged,
            this, &VkPlatformInputContext::slotInputContextVisibleChanged);
    }

    m_inputContext = context;

    if (m_inputContext)
    {
        connect(m_inputContext, &VkInputContext::visibleChanged,
            this, &VkPlatformInputContext::slotInputContextVisibleChanged);
    }
}

void VkPlatformInputContext::slotInputContextVisibleChanged()
{
    if (m_inputPanel)
    {
        m_inputPanel->setVisible(isInputPanelVisible());
    }

    emitInputPanelVisibleChanged();
}
