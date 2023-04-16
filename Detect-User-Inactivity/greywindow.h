#ifndef GREYWINDOW_H
#define GREYWINDOW_H

#include <QWidget>
#include <QDialog>

class GreyWindow : public QDialog
{
    Q_OBJECT
public:
    explicit GreyWindow(QWidget *parent = 0);

signals:
    void restartTimer();
protected:
	//detect when a QDialog is clicked anywhere
	void mousePressEvent(QMouseEvent* event) override;
};

#endif // GREYWINDOW_H
