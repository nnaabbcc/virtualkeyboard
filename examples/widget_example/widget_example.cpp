
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QFormLayout>
#include <QPushButton>

int main(int argc, char** argv)
{
    qputenv("QT_IM_MODULE", QByteArray("virtualkeyboard"));

    QApplication app(argc, argv);

    QWidget mainWidget;
    mainWidget.setWindowTitle("Widget Keyboard Test Example");

    auto layout = new QFormLayout;

    auto nameEdit = new QLineEdit;
    auto passEdit = new QLineEdit;
    auto commEdit = new QTextEdit;
    auto commitBtn = new QPushButton(QObject::tr("Commit"));

    passEdit->setEchoMode(QLineEdit::Password);
    layout->addRow(QObject::tr("&Name"), nameEdit);
    layout->addRow(QObject::tr("&Password"), passEdit);
    layout->addRow(QObject::tr("&Comment"), commEdit);
    layout->addWidget(commitBtn);

    mainWidget.setLayout(layout);
    mainWidget.show();

    return app.exec();
}