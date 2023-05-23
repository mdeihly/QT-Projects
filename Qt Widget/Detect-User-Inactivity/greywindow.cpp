#include "greywindow.h"

#define GREY_SEMI_TRANSPARENT_BKG "background-color: rgba(128, 128, 128, 127);"

GreyWindow::GreyWindow(QWidget *parent) :
        QDialog(parent)
{
    this->setStyleSheet(GREY_SEMI_TRANSPARENT_BKG);
    setWindowFlags(Qt::Widget |  Qt::FramelessWindowHint);
}

void GreyWindow::mousePressEvent(QMouseEvent* event)
{
	// hide grey window where user does a click
	this->hide();

    // when user click, restart the timer to detect inactivity
    emit restartTimer();

	QWidget::mousePressEvent(event);
}
