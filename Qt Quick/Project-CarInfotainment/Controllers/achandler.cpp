#include "achandler.h"

ACHandler::ACHandler(QObject *parent)
    : QObject{parent}
    ,m_targetTemperature(16)
    ,m_maxTemp(35)
{

}

int ACHandler::targetTemperature() const
{
    return m_targetTemperature;
}

void ACHandler::updateTemperature(int val)
{
    switch (val) {
    case INCREMENT:
        setTargetTemperature((m_targetTemperature + val) % (m_maxTemp+1));
        break;
    case DECREMENT:
        setTargetTemperature((m_targetTemperature + m_maxTemp) % (m_maxTemp+1));
    default:
        break;
    }
}

void ACHandler::setTargetTemperature(int newTargetTemperature)
{
    if (m_targetTemperature == newTargetTemperature)
        return;
    m_targetTemperature = newTargetTemperature;
    emit targetTemperatureChanged();
}
