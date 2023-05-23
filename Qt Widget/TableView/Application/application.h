#ifndef APPLICATION_H
#define APPLICATION_H
#include "../UserInterface/userinterface.h"
#include <QApplication>

class Application : public QApplication
{
    Q_OBJECT

public:
    Application(int &argc, char **argv);
    ~Application() = default;

    void showWidget();

private:
    UserInterface *m_ui{nullptr};
};
#endif // APPLICATION_H
