#ifndef PERSON_H
#define PERSON_H

#include <QMetaType>
#include <QMetaObject>
#include <QString>

class Person
{
    //Q_GADGET macro is a lighter version of the Q_OBJECT macro for classes that do not
    //inherit from QObject but still want to use some of the reflection capabilities
    //offered by QMetaObject
    Q_GADGET

    Q_PROPERTY(QString name MEMBER m_name)
    Q_PROPERTY(int age MEMBER m_age)

public:
    Person(const QString &name, int age);
    Person() = default;

private:
    QString m_name{""};
    int m_age;
};

#endif // PERSON_H
