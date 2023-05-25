#ifndef ACHANDLER_H
#define ACHANDLER_H

#include <QObject>

class ACHandler : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int targetTemperature READ targetTemperature WRITE setTargetTemperature NOTIFY targetTemperatureChanged)

    enum {INCREMENT = 1, DECREMENT = -1};

public:
    explicit ACHandler(QObject *parent = nullptr);

    int targetTemperature() const;

    Q_INVOKABLE void updateTemperature(int val);

    void setTargetTemperature(int newTargetTemperature);

signals:
    void targetTemperatureChanged();

private:
    int m_targetTemperature;
    const int m_maxTemp;
};

#endif // ACHANDLER_H
