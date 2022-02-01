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
    QPlatformInputContext::update(querys);
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
    if (m_inputContext == nullptr)
    {
        m_inputPanel = new VkInputPanel();
    }

    if (m_inputContext)
    {
        m_inputContext->showInputPanel();
    }

    if (m_inputPanel)
    {
        m_inputPanel->show();
    }
}

void VkPlatformInputContext::hideInputPanel()
{
    qDebug() << "hideInputPanel";
    if (m_inputContext)
    {
        m_inputContext->hideInputPanel();
    }

    if (m_inputPanel)
    {
        m_inputPanel->hide();
    }
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

    m_inputContext = context;
}