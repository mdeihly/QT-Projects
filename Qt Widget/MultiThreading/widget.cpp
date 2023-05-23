#include "widget.h"

#include <QGridLayout>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    init();
}

Widget::~Widget()
{
    if(nullptr != workerThread)
    {
        workerThread->quit();
        workerThread->wait();
        workerThread = nullptr;
    }
}

void Widget::init()
{
    createWidgets();
    createLayout();
    createWorkers();
    createConnections();

    resize(300,160);
}

void Widget::createWidgets()
{
    m_startBtn = new QPushButton("Start");
    m_stopBtn = new QPushButton("Stop");
    m_stopBtn->setEnabled(false);

    m_progBar = new QProgressBar;
    m_progBar->setMinimum(0);
    m_progBar->setMaximum(100);
    m_progBar->setValue(0);
    m_progBar->setFormat(QString::number(m_progBar->value())+"%");
}

void Widget::createLayout()
{
    auto layout = new QGridLayout(this);
    layout->addWidget(m_startBtn, 0, 0);
    layout->addWidget(m_stopBtn, 0, 1);
    layout->addWidget(m_progBar, 1, 0, 1, 2);
}

void Widget::createWorkers()
{
    workerThread = new QThread(this);
    workerObject = new Worker; // No Parent! Main (GUI) Thread

    // move to thread
    workerObject->moveToThread(workerThread);
}

void Widget::createConnections()
{
    bool connected = static_cast<bool>(connect(m_startBtn, &QPushButton::clicked,
                                               this, &Widget::onStartBtnClicked));

    connected &= static_cast<bool>(connect(m_stopBtn, &QPushButton::clicked,
                                           this, &Widget::onStopBtnClicked));

    connected &= static_cast<bool>(connect(workerThread, &QThread::started,
                                           workerObject, &Worker::doCounting));
    connected &= static_cast<bool>(connect(workerThread, &QThread::finished,
                                           workerObject, &Worker::deleteLater));

    connected &= static_cast<bool>(connect(workerObject, &Worker::currentCount,
                                           this, &Widget::onCurrentCount));

    connected &= static_cast<bool>(connect(workerObject, &Worker::countDone,
                                           workerThread, &QThread::quit));

    Q_ASSERT(connected);
    Q_UNUSED(connected);
}

void Widget::onCurrentCount(int currentCount)
{
    m_progBar->setValue(currentCount);
    m_progBar->setFormat(QString::number(currentCount)+"%");
}

void Widget::onStartBtnClicked()
{
    m_stopBtn->setEnabled(true);

    // start thread
    workerThread->start();
}

void Widget::onStopBtnClicked()
{
    m_startBtn->setEnabled(false);

    workerObject->setStop(true);
}
