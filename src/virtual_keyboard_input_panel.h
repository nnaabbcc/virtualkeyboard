#pragma once

#include <QWidget>
#include <QEvent>

class VkInputPanel : public QWidget
{
    Q_OBJECT

public:
    VkInputPanel(QWidget* parent = nullptr);
    virtual ~VkInputPanel();

private Q_SLOTS:
    void slotKeyPressed();
    void slotKeyReleased();

Q_SIGNALS:
    void emitEvent(QEvent* event);

};