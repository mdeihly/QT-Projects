#include "system.h"
#include <QTime>
#include <QTimer>
System::System(QObject *parent)
    : QObject{parent}
    , m_carLocked{true}
    , m_outdoorTemp{22}
{
    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout,
            this, &System::onTimeout);

    m_timer->start(500);
}

bool System::name() const
{
    return m_carLocked;
}

void System::setCarLocked(bool newCarLocked)
{
    if (m_carLocked == newCarLocked)
        return;
    m_carLocked = newCarLocked;
    emit carLockedChanged();
}

int System::outdoorTemp() const
{
    return m_outdoorTemp;
}

void System::setOutdoorTemp(int newOutdoorTemp)
{
    if (m_outdoorTemp == newOutdoorTemp)
        return;
    m_outdoorTemp = newOutdoorTemp;
    emit outdoorTempChanged();
}

QString System::currentTime() const
{
    return m_currentTime;
}

void System::setCurrentTime(const QString &newCurrentTime)
{
    if (m_currentTime == newCurrentTime)
        return;
    m_currentTime = newCurrentTime;
    emit currentTimeChanged();
}

void System::onTimeout()
{
    setCurrentTime(QTime::currentTime().toString("hh:mmap"));

    // update Outdoor Temperature randomly (20,30)
    setOutdoorTemp(rand() % (30-20) + 20);
}
