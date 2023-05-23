#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include <QObject>
#include <QVector>
class Student;

class StudentList : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int count READ count CONSTANT) // Read-only
public:
    explicit StudentList(QObject *parent = nullptr);

    int count() const;

    Q_INVOKABLE QObject* studentAtIndex(int index) const;

signals:

private:
    QVector<Student*> m_students;
};

#endif // STUDENTLIST_H
