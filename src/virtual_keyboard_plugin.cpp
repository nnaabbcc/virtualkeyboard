#include "virtual_keyboard_plugin.h"
#include "virtual_keyboard_context.h"
#include "register_qml_types.h"

QPlatformInputContext*
VkPlatformInputContextPlugin::create(
    const QString &key,
    const QStringList & /*paramList*/
)
{
    if (key == QString("virtualkeyboard"))
    {
        registerQmlTypes();
        return VkPlatformInputContext::instance();
    }

    return nullptr;
}