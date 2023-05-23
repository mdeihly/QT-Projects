#include "maindialog.h"

#include <QApplication>
#include <QShortcut>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainDialog w;
    w.show();

    auto shortcut = new QShortcut(Qt::CTRL | Qt::Key_Q, &w);
    shortcut->setContext(Qt::ApplicationShortcut);
    QObject::connect(shortcut, &QShortcut::activated,
                     qApp, QCoreApplication::quit);

    return a.exec();
}
