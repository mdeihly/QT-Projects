#include "rightsidewidget.h"
#include <QHBoxLayout>

RightSideWidget::RightSideWidget(QWidget *parent)
    : QWidget{parent}
{
    init();
}

void RightSideWidget::init()
{
    setAttribute(Qt::WA_StyledBackground, true);

    createWidgets();
    createLayout();
}

void RightSideWidget::createWidgets()
{
    m_sp1 = new CustomSpinBpx;
    m_sp2 = new CustomSpinBpx;
}

void RightSideWidget::createLayout()
{
    auto hLayout = new QHBoxLayout;
    hLayout->addWidget(m_sp1);
    hLayout->addWidget(m_sp2);

    setLayout(hLayout);
}
