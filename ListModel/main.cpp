#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>

#include "model.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    Model model;

    qmlRegisterSingletonInstance("List.Model",
                                 1,
                                 0,
                                 "MyModel",&model);

    QQuickView view;
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.setSource(QUrl(QStringLiteral("qrc:/main.qml")));
    view.show();

    return app.exec();
}
