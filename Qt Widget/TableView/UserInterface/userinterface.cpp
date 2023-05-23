#include "userinterface.h"
#include "ModelView/modelviewwidget.h"
#include <QHBoxLayout>
#include <QPointer>

UserInterface::UserInterface(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("TableView");
    resize(700,500);
    auto widget = new GUI::ModelViewWidget(this);

    auto layout = new QHBoxLayout;
    layout->addWidget(widget);
    setLayout(layout);
}
