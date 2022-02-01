#include "register_qml_types.h"
#include "virtual_keyboard_input_context.h"
#include <QtQml>

static QObject* createInputContext(QQmlEngine *engine,
    QJSEngine *scriptEngine)
{
    return new VkInputContext(engine, scriptEngine);
}

void registerQmlTypes()
{
    Q_INIT_RESOURCE(virtual_keyboard);

    auto uri = "com.nnaabbcc.virtualkeyboard";
    qmlRegisterSingletonType<VkInputContext>(uri, 1, 0, "InputContext",
        createInputContext);

    QString path = "qrc:///virtual_keyboard/";
    qmlRegisterType(QUrl(path + "InputPanel.qml"), uri, 1, 0, "InputPanel");

    // ToDo
}
