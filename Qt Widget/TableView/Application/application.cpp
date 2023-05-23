#include "application.h"

Application::Application(int &argc, char **argv)
    : QApplication(argc, argv)
{
    m_ui = new UserInterface();
    m_ui->setAttribute(Qt::WA_DeleteOnClose);
}

void Application::showWidget()
{
    m_ui->show();
}

