#pragma once

#include <qpa/qplatforminputcontext.h>

class VkInputContext;
class VkInputPanel;

class VkPlatformInputContext : public QPlatformInputContext
{
    Q_OBJECT

protected:
    VkPlatformInputContext();

public:
    static VkPlatformInputContext* instance();
    static VkPlatformInputContext* create();
    static void destory();

    virtual ~VkPlatformInputContext();

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
    QObject* focusObject();
    void setInputContext(VkInputContext* context);

private:
    VkInputContext* m_inputContext;
    VkInputPanel* m_inputPanel;
    QObject* m_focusObject = nullptr;
};