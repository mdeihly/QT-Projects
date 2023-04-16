#ifndef LED_H
#define LED_H

#include <QWidget>
#include <QLabel>

class QTimer;

class Led : public QLabel
{
    Q_OBJECT

public:
    Led(QWidget *parent = nullptr);

    void onActivateLed(const QColor &color);

private slots:
    void onTimeout();

private:
    QTimer *m_timer{nullptr};
};

#endif // LED_H
