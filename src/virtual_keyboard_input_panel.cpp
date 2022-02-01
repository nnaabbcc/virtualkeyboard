#include "virtual_keyboard_input_panel.h"
#include <QGuiApplication>
#include <QScreen>

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

    auto w = 1280;
    auto h = 300;
    auto screen = qGuiApp->primaryScreen();
    auto geo = screen->geometry();
    setGeometry(geo.x() + (geo.width() - w) / 2,
        geo.height() - h,
        w,
        h);
}

VkInputPanel::~VkInputPanel()
{}
