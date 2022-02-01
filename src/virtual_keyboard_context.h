#pragma once

#include <qpa/qplatforminputcontext.h>
#include "virtual_keyboard_input_panel.h"

class VirtualKeyboardInputContext : public QPlatformInputContext
{
    Q_OBJECT

public:
    VirtualKeyboardInputContext();
    virtual ~VirtualKeyboardInputContext();

    bool isValid() const override;
    bool hasCapability(Capability capability) const override;

    void reset() override;
    void commit() override;
    void update(Qt::InputMethodQueries) override;
    void invokeAction(QInputMethod::Action, int cursorPosition) override;
    bool filterEvent(const QEvent* event) override;
    QRectF keyboardRect() const override;

    bool isAnimating() const override;

    void showInputPanel() override;
    void hideInputPanel() override;
    bool isInputPanelVisible() const override;

    QLocale locale() const override;
    Qt::LayoutDirection inputDirection() const override;

    void setFocusObject(QObject* object) override;

private:
    void slotInputEvent(QEvent* event);

private:
    VkInputPanel * m_inputPanel;
    QObject* m_focusObject = nullptr;
};