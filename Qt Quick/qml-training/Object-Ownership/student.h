#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name MEMBER m_name NOTIFY nameChanged)
public:
    explicit Student(const QString &name = QString());

signals:
    void nameChanged();
private:
    QString m_name;
};

#endif // STUDENT_H
