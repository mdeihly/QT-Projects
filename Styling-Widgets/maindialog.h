#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QDialog>
#include "CustomWidgets/clickableimage.h"
#include "SplitterWidgets/leftsidewidget.h"
#include "SplitterWidgets/rightsidewidget.h"

QT_BEGIN_NAMESPACE
class QSplitter;
class QLineEdit;
QT_END_NAMESPACE

class MainDialog : public QDialog
{
    Q_OBJECT
public:
    MainDialog(QWidget *parent = nullptr);

private:
    void init();
    void createWidgets();
    void createLayout();
    void createConnections();
    void loadStylesheet();

private:
    QSplitter *m_splitter;

    ClickableImage *clickImg{nullptr};
    LeftSideWidget *leftWidget{nullptr};
    RightSideWidget *rightWidget{nullptr};
};

#endif // MAINDIALOG_H
