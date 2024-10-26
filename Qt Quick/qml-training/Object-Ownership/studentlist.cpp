#include "studentlist.h"
#include <QQmlEngine>
#include "student.h"
StudentList::StudentList(QObject *parent)
    : QObject{parent}
{
    m_students << new Student("Alessio");
    m_students << new Student("Mauro");
    m_students << new Student("Alex");
}

int StudentList::count() const
{
    return m_students.count();
}

QObject *StudentList::studentAtIndex(int index) const
{
    if (index < 0 || index >= m_students.count())
        return nullptr;

    // When data is transferred from C++ to QML, the ownership of the data always remains with C++.
    //The exception to this rule is when a QObject is returned from an explicit C++ method call:
    //in this case, the QML engine assumes ownership of the object ..
    //unless the ownership of the object has explicitly been set to remain with C++ by invoking ..
    //QQmlEngine::setObjectOwnership() with QQmlEngine::CppOwnership specified.
    QQmlEngine::setObjectOwnership(m_students[index], QQmlEngine::CppOwnership);

    return m_students[index];
}
