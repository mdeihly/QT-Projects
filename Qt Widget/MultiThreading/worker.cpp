#include "worker.h"

#include <QVariant>
#include <QThread>
#include <QDebug>
#include <QMutexLocker>

Worker::Worker(QObject *parent)
    : QObject{parent}
{
    qDebug() << "Worker running in thread .. " << QThread::currentThread();
}

void Worker::doCounting()
{
    qDebug() << "Counting method running in thread .. " << QThread::currentThread();

    // Heavy Task -- going to run in secondary thread to not block GUI
    for(int i = 0; i < 1000000001; i++)
    {
        if(true == stop)
        {
            break;
        }
        auto percentage = (i/1000000000.0)* 100.0;

        if((i%100000) == 0)
        {
            emit currentCount(QVariant::fromValue(percentage).toInt());
        }
    }

    emit countDone();
}

void Worker::setStop(bool newStop)
{
    const QMutexLocker locker(&mutex);
    stop = newStop;
}
