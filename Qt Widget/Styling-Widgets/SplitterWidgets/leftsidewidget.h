#ifndef LEFTSIDEWIDGET_H
#define LEFTSIDEWIDGET_H

#include <QWidget>
#include "CustomWidgets/customlineedit.h"

class QLabel;
class QProgressBar;
class QCheckBox;

class LeftSideWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LeftSideWidget(QWidget *parent = nullptr);

private:
    void init();
    void createWidgets();
    void createLayout();
    void createConnections();

private:
    CustomLineEdit *m_pressureLineEdit{nullptr};
    CustomLineEdit *m_tempLineEdit{nullptr};

    QLabel *m_pressureLabel{nullptr};
    QLabel *m_tempLabel{nullptr};
    QLabel *m_value{nullptr};
    QLabel *m_minMax{nullptr};

    QProgressBar *m_progBar{nullptr};

    QCheckBox *m_chkb{nullptr};

    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
};

#endif // LEFTSIDEWIDGET_H
