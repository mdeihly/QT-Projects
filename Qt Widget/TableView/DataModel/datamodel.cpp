#include "datamodel.h"

namespace Data
{
void DataModel::setTitle(const QString &newTitle)
{
    m_title = newTitle;
}

QString DataModel::getTitle() const
{
    return m_title;
}

void DataModel::setDescription(const QString &newDescription)
{
    m_Description = newDescription;
}

QString DataModel::getDescription() const
{
    return m_Description;
}

QDateTime DataModel::getStart() const
{
    return m_Start;
}

void DataModel::setStart(const QDateTime &newStart)
{
    m_Start = newStart;
}

QDateTime DataModel::getStop() const
{
    return m_Stop;
}

void DataModel::setStop(const QDateTime &newStop)
{
    m_Stop = newStop;
}

int DataModel::getDone() const
{
    return m_Done;
}

void DataModel::setDone(int newDone)
{
    m_Done = newDone;
}

}
