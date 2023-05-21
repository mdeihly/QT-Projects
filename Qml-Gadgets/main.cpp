#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>
#include "person.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QQuickView view;
    qRegisterMetaType<Person>();

    view.engine()->rootContext()->setContextProperty("_player", QVariant::fromValue(Person("Player", 30)));

    view.setSource(QUrl("qrc:/main.qml"));
    view.show();

    return app.exec();
}
