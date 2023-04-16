#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QDialog>
class QTimer;
QT_BEGIN_NAMESPACE
namespace Ui { class MainDialog; }
QT_END_NAMESPACE

#include "greywindow.h"

class MainDialog : public QDialog
{
    Q_OBJECT

public:
    MainDialog(QWidget *parent = nullptr);
    ~MainDialog();
    bool eventFilter(QObject *watched, QEvent *event);

private slots:
    void onRestartTimer();
    void onTimeout();

signals:
    void showGreyWindow();

private:
    void init();
    void createWidgets();
    void createConnections();
private:
    Ui::MainDialog *ui;
    QTimer *m_timer{nullptr};
    GreyWindow *greyWin{nullptr};
    int startTime{0};
    const int timerDuration = 1; // 1 [min], after 1 min of inactivity, grey window appears
};

#endif // MAINDIALOG_H
