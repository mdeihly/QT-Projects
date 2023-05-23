#include "calculator.h"

#include <QGridLayout>
#include <QSignalMapper>

Calculator::Calculator(QWidget *parent)
    : QWidget(parent)
{
    init();
    setWindowTitle("Calculator Application");
    resize(400,400);
}

void Calculator::init()
{
    createWidgets();
    createLayout();
    createConnections();
}

void Calculator::createWidgets()
{
    m_button0     = new QPushButton("0");
    m_button1     = new QPushButton("1");
    m_button2     = new QPushButton("2");
    m_button3     = new QPushButton("3");
    m_button4     = new QPushButton("4");
    m_button5     = new QPushButton("5");
    m_button6     = new QPushButton("6");
    m_button7     = new QPushButton("7");
    m_button8     = new QPushButton("8");
    m_button9     = new QPushButton("9");
    m_buttonDot   = new QPushButton(".");
    m_buttonCancel= new QPushButton("<-");
    m_buttonClear = new QPushButton("C");
    m_buttonClear->setStyleSheet("background-color: orange;");

    m_lineEdit = new QLineEdit;
    m_lineEdit->setAlignment( Qt::AlignRight );
}

void Calculator::createLayout()
{
    auto layout = new QGridLayout;

    layout->addWidget( m_lineEdit, 0, 0, 1, 3 );

    layout->addWidget(m_button1, 1, 0);
    layout->addWidget(m_button2, 1, 1);
    layout->addWidget(m_button3, 1, 2);
    layout->addWidget(m_button4, 2, 0);
    layout->addWidget(m_button5, 2, 1);
    layout->addWidget(m_button6, 2, 2);
    layout->addWidget(m_button7, 3, 0);
    layout->addWidget(m_button8, 3, 1);
    layout->addWidget(m_button9, 3, 2);
    layout->addWidget(m_button0, 4, 0);
    layout->addWidget(m_buttonDot, 4, 1);
    layout->addWidget(m_buttonCancel, 4, 2);
    layout->addWidget(m_buttonClear, 5, 1);

    this->setLayout(layout);
}

void Calculator::createConnections()
{
    QSignalMapper *mapper = new QSignalMapper(this);

    mapper->setMapping(m_button0, "0");
    mapper->setMapping(m_button1, "1");
    mapper->setMapping(m_button2, "2");
    mapper->setMapping(m_button3, "3");
    mapper->setMapping(m_button4, "4");
    mapper->setMapping(m_button5, "5");
    mapper->setMapping(m_button6, "6");
    mapper->setMapping(m_button7, "7");
    mapper->setMapping(m_button8, "8");
    mapper->setMapping(m_button9, "9");
    mapper->setMapping(m_buttonDot, ".");

    connect(m_button0, &QPushButton::clicked,
            mapper, QOverload<>::of(&QSignalMapper::map));
    connect(m_button1, &QPushButton::clicked,
            mapper, QOverload<>::of(&QSignalMapper::map));
    connect(m_button2, &QPushButton::clicked,
            mapper, QOverload<>::of(&QSignalMapper::map));
    connect(m_button3, &QPushButton::clicked,
            mapper, QOverload<>::of(&QSignalMapper::map));
    connect(m_button4, &QPushButton::clicked,
            mapper, QOverload<>::of(&QSignalMapper::map));
    connect(m_button5, &QPushButton::clicked,
            mapper, QOverload<>::of(&QSignalMapper::map));
    connect(m_button6, &QPushButton::clicked,
            mapper, QOverload<>::of(&QSignalMapper::map));
    connect(m_button7, &QPushButton::clicked,
            mapper, QOverload<>::of(&QSignalMapper::map));
    connect(m_button8, &QPushButton::clicked,
            mapper, QOverload<>::of(&QSignalMapper::map));
    connect(m_button9, &QPushButton::clicked,
            mapper, QOverload<>::of(&QSignalMapper::map));
    connect(m_buttonDot, &QPushButton::clicked,
            mapper, QOverload<>::of(&QSignalMapper::map));

    connect(mapper, &QSignalMapper::mappedString,
            this, &Calculator::onButtonClicked);

    connect(m_buttonCancel, &QPushButton::clicked,
            this, &Calculator::removeDigit);

    connect(m_buttonClear, &QPushButton::clicked,
            m_lineEdit, &QLineEdit::clear);

    connect( m_lineEdit, &QLineEdit::textChanged,
             this, &Calculator::setText);
}

void Calculator::onButtonClicked(const QString &newText)
{
    setText(this->text + newText);
}

void Calculator::setText(const QString &newText)
{
    if( newText == this->text )
        return;

    this->text = newText;
    m_lineEdit->setText(text);

    emit textChanged(text);
}

void Calculator::removeDigit()
{
    if(false == text.isEmpty())
    {
        text.chop(1);
        m_lineEdit->setText(text);
    }
}

