#ifndef WIDGET_H
#define WIDGET_H

#include "worker.h"

#include <QWidget>
#include <QPushButton>
#include <QProgressBar>
#include <QThread>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void onCurrentCount(int currentCount);
    void onStartBtnClicked();
    void onStopBtnClicked();
private:
    void init();
    void createWidgets();
    void createLayout();
    void createWorkers();
    void createConnections();

private:
    QPushButton *m_startBtn{nullptr};
    QPushButton *m_stopBtn{nullptr};

    QProgressBar *m_progBar{nullptr};

    QThread *workerThread{nullptr};
    Worker *workerObject{nullptr};
};
#endif // WIDGET_H
