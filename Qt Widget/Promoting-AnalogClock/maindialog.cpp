#include "maindialog.h"
#include "ui_maindialog.h"

MainDialog::MainDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainDialog)
{
    ui->setupUi(this);

    connect(ui->widget, &AnalogClock::updateTime,
            this, [this](QTime &currentTime)
    {
        ui->timeEdit->setTime(currentTime);
    });

    setWindowTitle("Analog Clock");
    resize(400,400);
}

MainDialog::~MainDialog()
{
    delete ui;
}

