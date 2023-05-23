#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QMutex>

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);
    ~Worker() = default;

    void setStop(bool newStop);

signals:
    void currentCount(int count);
    void countDone();

public slots:
    void doCounting();

private:
    bool stop{false};
    QMutex mutex; // protects stop

};

#endif // WORKER_H
