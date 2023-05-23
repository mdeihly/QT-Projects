#include "maindialog.h"
#include <QVBoxLayout>
#include <QSplitter>
#include <QFile>

MainDialog::MainDialog(QWidget *parent)
    :QDialog(parent)
{
    init();
}

void MainDialog::init()
{
    setWindowFlags(Qt::FramelessWindowHint| Qt::WindowSystemMenuHint);
    setAttribute(Qt::WA_StyledBackground, true);
    setObjectName("MainDialog");
    resize(600,220);

    createWidgets();
    createLayout();
    createConnections();
    loadStylesheet();
}

void MainDialog::createWidgets()
{
    m_splitter = new QSplitter;
    m_splitter->setHandleWidth(20);

    clickImg = new ClickableImage;
    clickImg->setImage(":/Images/CmdCancel.png");
    clickImg->setCursor(Qt::PointingHandCursor);

    leftWidget = new LeftSideWidget;
    leftWidget->setObjectName("LeftWidget");

    rightWidget = new RightSideWidget;
    rightWidget->setObjectName("RightWidget");
}

void MainDialog::createLayout()
{
    auto vlayout = new QVBoxLayout;

    m_splitter->addWidget(leftWidget);
    m_splitter->addWidget(rightWidget);

    vlayout->addWidget(clickImg);
    vlayout->setAlignment(clickImg, {Qt::AlignTop, Qt::AlignRight});
    vlayout->addWidget(m_splitter);

    setLayout(vlayout);
}

void MainDialog::createConnections()
{
    QObject::connect(clickImg, &ClickableImage::clicked,
                     this, &MainDialog::close);
}

void MainDialog::loadStylesheet()
{
    QFile file(":/StylesheetFile/stylesheet.qss");
    if(file.open(QFile::ReadOnly))
    {
        QString styleSheet = QLatin1String(file.readAll());
        setStyleSheet(styleSheet);
    }
}
