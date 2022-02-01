#include "virtual_keyboard_input_panel.h"

#include <QPushButton>
#include <QGridLayout>
#include <QVariant>
#include <QKeyEvent>
#include <QDebug>

VkInputPanel::VkInputPanel(QWidget* parent)
    : QWidget(parent)
{
    setWindowFlag(Qt::WindowDoesNotAcceptFocus);
    setWindowFlag(Qt::WindowStaysOnTopHint);
    setWindowFlag(Qt::BypassWindowManagerHint);
    setWindowFlag(Qt::FramelessWindowHint);
    setWindowFlag(Qt::Tool);

    auto layout = new QGridLayout;

    struct KeyItem {
        int key;
        QString label;
    } keys[] = {
        { Qt::Key_0, "0" },
        { Qt::Key_P, "p" },
        { Qt::Key_F3, "F3" },
        { Qt::Key_Tab, "Tab" },
        { Qt::Key_Backspace, "<-" },
        { Qt::Key_Enter, "Enter"}
    };

    int col = 0;
    for (auto key : keys)
    {
        auto button = new QPushButton(key.label);
        button->setProperty("Key", key.key);
        button->setAutoRepeat(true);
        connect(button, SIGNAL(pressed()),
            this, SLOT(slotKeyPressed()));
        connect(button, SIGNAL(released()),
            this, SLOT(slotKeyReleased()));
        layout->addWidget(button, 0, col);
        col++;
    }

    setLayout(layout);
}

VkInputPanel::~VkInputPanel()
{

}

void VkInputPanel::slotKeyPressed()
{
    auto button = qobject_cast<QPushButton*>(sender());
    auto key = button->property("Key").toInt();
    qDebug() << "Press key" << key;

    auto event = new QKeyEvent(QEvent::KeyPress,
        key,
        Qt::NoModifier,
        button->text());
    emitEvent(event);
    delete event;
}

void VkInputPanel::slotKeyReleased()
{
    auto button = qobject_cast<QPushButton*>(sender());
    auto key = button->property("Key").toInt();
    qDebug() << "Release key" << key;

    auto event = new QKeyEvent(QEvent::KeyRelease,
        key,
        Qt::NoModifier,
        button->text());
    emitEvent(event);
    delete event;
}