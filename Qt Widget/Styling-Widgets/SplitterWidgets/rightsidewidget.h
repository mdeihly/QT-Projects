#ifndef RIGHTSIDEWIDGET_H
#define RIGHTSIDEWIDGET_H

#include <QWidget>
#include "CustomWidgets/customspinbpx.h"

class QSpinBox;

class RightSideWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RightSideWidget(QWidget *parent = nullptr);

private:
    void init();
    void createWidgets();
    void createLayout();

private:
    CustomSpinBpx *m_sp1{nullptr};
    CustomSpinBpx *m_sp2{nullptr};

};

#endif // RIGHTSIDEWIDGET_H
