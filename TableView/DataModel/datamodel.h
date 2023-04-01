#ifndef DATAMODEL_H
#define DATAMODEL_H

#include <QString>
#include <QDateTime>

namespace Data
{
class DataModel
{
public:
    DataModel() = default;

    void setTitle(const QString &newTitle);
    QString getTitle() const;

    void setDescription(const QString &newDescription);
    QString getDescription() const;

    QDateTime getStart() const;
    void setStart(const QDateTime &newStart);

    QDateTime getStop() const;
    void setStop(const QDateTime &newStop);

    int getDone() const;
    void setDone(int newDone);

private:
    QString m_title;
    QString m_Description;
    QDateTime m_Start;
    QDateTime m_Stop;
    int m_Done {};
};
}


#endif // DATAMODEL_H
