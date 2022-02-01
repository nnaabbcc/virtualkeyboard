#include "virtual_keyboard_plugin.h"
#include "virtual_keyboard_context.h"

QPlatformInputContext*
VirtualKeyboardInputContextPlugin::create(
    const QString &key,
    const QStringList & /*paramList*/
)
{
    if (key == QString("virtualkeyboard"))
    {
        return new VirtualKeyboardInputContext;
    }

    return nullptr;
}