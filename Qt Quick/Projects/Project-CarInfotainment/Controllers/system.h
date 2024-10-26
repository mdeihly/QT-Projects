#ifndef SYSTEM_H
#define SYSTEM_H

#include <QObject>

class QTimer;

class System : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool carLocked READ name WRITE setCarLocked NOTIFY carLockedChanged)
    Q_PROPERTY(int outdoorTemp READ outdoorTemp WRITE setOutdoorTemp NOTIFY outdoorTempChanged)
    Q_PROPERTY(QString currentTime READ currentTime WRITE setCurrentTime NOTIFY currentTimeChanged)

public:
    explicit System(QObject *parent = nullptr);
    bool name() const;
    int outdoorTemp() const;
    QString currentTime() const;
    void setOutdoorTemp(int newOutdoorTemp);
    void setCurrentTime(const QString &newCurrentTime);

public slots:
    void setCarLocked(bool newCarLocked);

private slots:
    void onTimeout();

signals:
    void carLockedChanged();
    void outdoorTempChanged();
    void currentTimeChanged();

private:
    bool m_carLocked;
    int m_outdoorTemp;
    QString m_username;
    QString m_currentTime;
    QTimer *m_timer{nullptr};
};

#endif // SYSTEM_H
