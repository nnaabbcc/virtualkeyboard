#pragma once

#include <qpa/qplatforminputcontextplugin_p.h>

class VirtualKeyboardInputContextPlugin : public QPlatformInputContextPlugin
{
    Q_OBJECT

    Q_PLUGIN_METADATA(IID QPlatformInputContextFactoryInterface_iid FILE "virtualkeyboard.json")

public:
    QPlatformInputContext* create(
        const QString &key,
        const QStringList &paramList) override;
};