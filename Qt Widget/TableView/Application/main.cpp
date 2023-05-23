#include "application.h"
#include <exception>

int main(int argc, char *argv[])
{
    Application app(argc, argv);
    app.showWidget();

    return app.exec();
}
