#include "leftsidewidget.h"

#include <QGridLayout>
#include <QLabel>
#include <QProgressBar>
#include <QCheckBox>
#include <QShortcut>

LeftSideWidget::LeftSideWidget(QWidget *parent)
    : QWidget{parent}
{
    init();
}

void LeftSideWidget::init()
{
    setAttribute(Qt::WA_StyledBackground, true);

    createWidgets();
    createLayout();
    createConnections();
}

void LeftSideWidget::createWidgets()
{
    m_pressureLabel = new QLabel("Pressure");
    m_tempLabel = new QLabel("Temperature");
    m_value = new QLabel("Value");
    m_minMax = new QLabel("[0-75]");

    m_pressureLineEdit = new CustomLineEdit;

    m_tempLineEdit = new CustomLineEdit;

    m_progBar = new QProgressBar();
    m_progBar->setMinimum(0);
    m_progBar->setMaximum(100);
    m_progBar->setValue(21); // initial value

    m_chkb = new QCheckBox("Show Progress\nBar");
    m_chkb->setCursor(Qt::PointingHandCursor);
    m_chkb->setCheckState(Qt::Checked);
}

void LeftSideWidget::createLayout()
{
    auto grid = new QGridLayout;

    grid->addWidget(m_pressureLabel, 0, 1, Qt::AlignCenter);
    grid->addWidget(m_tempLabel, 0, 2, Qt::AlignCenter);
    grid->addWidget(m_value, 1, 0, Qt::AlignCenter);
    grid->addWidget(m_pressureLineEdit, 1, 1, Qt::AlignCenter);
    grid->addWidget(m_tempLineEdit, 1, 2, Qt::AlignCenter);
    grid->addWidget(m_minMax, 1, 3, Qt::AlignLeft);

    grid->addWidget(m_progBar, 2, 1, 1, 2);

    grid->addWidget(m_chkb, 2, 0);

    this->setLayout(grid);
}

void LeftSideWidget::createConnections()
{
    auto plusShortcut = new QShortcut(Qt::Key_Plus, this);
    connect(plusShortcut, &QShortcut::activated,
            this, [this]()
    {
        const int value = (m_progBar->value() + 1) % 101;
        m_progBar->setValue(value);
    });

    auto minusShortcut = new QShortcut(Qt::Key_Minus, this);
    connect(minusShortcut, &QShortcut::activated,
            this, [this]()
    {
        const int value = (m_progBar->value() + 100) % 101;
        m_progBar->setValue(value);
    });

    connect(m_chkb, &QCheckBox::clicked,
            this, [this](bool checked) { m_progBar->setVisible(checked); });
}

void LeftSideWidget::mousePressEvent(QMouseEvent *event)
{
    // clear focus from QLineEdit when anyplace on the window is clicked
    auto focusedWidget = this->focusWidget();

    QString className = QString(typeid(*focusedWidget).name());
    if(className.contains("CustomLineEdit"))
    {
        focusedWidget->clearFocus();
    }

    QWidget::mousePressEvent(event);
}
