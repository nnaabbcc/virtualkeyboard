#include "virtual_keyboard_input_panel.h"

VkInputPanel::VkInputPanel(QWindow* parent)
    : QQuickView(parent)
{
    setFlag(Qt::WindowDoesNotAcceptFocus);
    setFlag(Qt::WindowStaysOnTopHint);
    setFlag(Qt::BypassWindowManagerHint);
    setFlag(Qt::FramelessWindowHint);
    setFlag(Qt::Tool);

    setResizeMode(QQuickView::SizeRootObjectToView);
    setSource(QUrl("qrc:///virtual_keyboard/InputPanel.qml"));
    setGeometry(0, 0, 800, 300);
}

VkInputPanel::~VkInputPanel()
{}
