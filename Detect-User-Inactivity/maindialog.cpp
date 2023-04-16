#include "maindialog.h"
#include "ui_maindialog.h"
#include <QDateTime>
#include <QTimer>

MainDialog::MainDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainDialog)
{
    ui->setupUi(this);

    init();
}

MainDialog::~MainDialog()
{
    delete ui;
}

void MainDialog::init()
{
    createWidgets();
    createConnections();

    // install event filter
    qApp->installEventFilter(this);

    ui->remainingTimeLineEdit->setText(QString::number(timerDuration*60));
}

void MainDialog::createWidgets()
{
    m_timer = new QTimer(this);
    startTime = QDateTime::currentDateTime().toSecsSinceEpoch();
    m_timer->start(1000);

    greyWin = new GreyWindow(this);
    greyWin->hide();
    greyWin->resize(this->size()*5); // resize it to cover all main dialog
}

void MainDialog::createConnections()
{
    connect(m_timer, &QTimer::timeout,
            this, &MainDialog::onTimeout);

    connect(greyWin, &GreyWindow::restartTimer,
            this, &MainDialog::onRestartTimer);
}
void MainDialog::onTimeout()
{
    int sec = QDateTime::currentDateTime().toSecsSinceEpoch();
    int currentSec = timerDuration*60-(sec-startTime);

    ui->remainingTimeLineEdit->setText(QString::number(currentSec));//countdown

    if(std::isless(currentSec,10) && std::isgreater(currentSec,0))
    {
        // last 10 seconds --> Red blinking Led
        ui->ledLabel->onActivateLed(Qt::red);

    }
    else if(0 == currentSec)
    {
        qInfo("Auto log-off occurred..");

        // auto log-off occurred --> show grey window
        greyWin->show();
        // stop timer
        m_timer->stop();

        // remove event filter
        qApp->removeEventFilter(this);
    }
    else
    {
        // normal blinking LED
        ui->ledLabel->onActivateLed(Qt::green);
    }


}



bool MainDialog::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type() == QEvent::MouseButtonPress)
    {
        startTime = QDateTime::currentDateTime().toSecsSinceEpoch();
    }

    //	default --- standard event processing
    return QObject::eventFilter(watched,event);
}

void MainDialog::onRestartTimer()
{
    startTime = QDateTime::currentDateTime().toSecsSinceEpoch();
    m_timer->start(1000);

    // install again event filter
    qApp->installEventFilter(this);
}

