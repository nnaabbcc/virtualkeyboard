#pragma once

#include <QQuickView>

class VkInputPanel : public QQuickView
{
    Q_OBJECT

public:
    VkInputPanel(QWindow* parent = nullptr);
    virtual ~VkInputPanel();

};
