#ifndef ANALOGCLOCK_H
#define ANALOGCLOCK_H

#include <QWidget>

class AnalogClock : public QWidget
{
    Q_OBJECT

public:
    explicit AnalogClock(QWidget *parent = nullptr);

signals:
    //!
    //! \brief updateTime is emitted to update QTimeEdit
    //! \param data is the current Time.
    //!
    void updateTime(QTime &data);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    void init();
};

#endif // ANALOGCLOCK_H
