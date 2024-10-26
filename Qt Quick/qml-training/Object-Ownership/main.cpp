#include <QGuiApplication>
#include <QQmlContext>
#include <QQuickView>
#include "studentlist.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQuickView view;

    StudentList studentList;
    view.rootContext()->setContextProperty("_studentList", &studentList);
    view.setSource(QUrl("qrc:///main.qml"));
    view.show();

    return app.exec();
}
