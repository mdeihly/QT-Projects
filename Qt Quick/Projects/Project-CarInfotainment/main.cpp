#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <Controllers/system.h>
#include <Controllers/achandler.h>

int main(int argc, char *argv[])
{
    QGuiApplication::setApplicationName("Automotive");

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    System systemHandler;
    ACHandler acHandler;

    QQmlContext *context = engine.rootContext();
    context->setContextProperty("_systemHandler", &systemHandler);
    context->setContextProperty("_acHandler", &acHandler);

    engine.load("qrc:/main.qml");
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
