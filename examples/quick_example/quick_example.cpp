
#include <QGuiApplication>
#include <QQuickView>
#include <QUrl>

int main(int argc, char** argv)
{
    qputenv("QT_IM_MODULE", QByteArray("virtualkeyboard"));

    QGuiApplication app(argc, argv);

    QQuickView view;
    view.setTitle(QObject::tr("Quick Example"));
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.setSource(QUrl("qrc:/quick_example.qml"));
    view.show();

    return app.exec();
}
