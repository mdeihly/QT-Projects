#include "led.h"
#include <QTimer>

Led::Led(QWidget *parent):
    QLabel(parent)
{
    m_timer = new QTimer(this);
    m_timer->setSingleShot(true);
    connect(m_timer, &QTimer::timeout,
            this, &Led::onTimeout);

}

void Led::onTimeout()
{
    this->setStyleSheet("background-color: rgb(255, 255, 255);\n"
                                          "border-radius:9px;\n"
                                          "border: 1px solid gray; \n"
                                          "\n"
                                          "");
}

void Led::onActivateLed(const QColor &color)
{
    m_timer->start(200);

    this->setStyleSheet("background-color: "+color.name(QColor::HexArgb)+";\n"
                                          "border-radius:9px;\n"
                                          "border: 1px solid gray; \n"
                                          "\n"
                                          "");

}
