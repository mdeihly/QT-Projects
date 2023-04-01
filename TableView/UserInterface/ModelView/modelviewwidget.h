#ifndef MODELVIEWWIDGET_H
#define MODELVIEWWIDGET_H

#include "../TableModel/tablemodel.h"
#include "Delegates/datetimedelegate.h"
#include "Delegates/SpinBoxDelegate.h"
#include "Delegates/titledelegate.h"
#include "Delegates/DescriptionDelegate.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
class QTableView;
class QLabel;
class QPushButton;
QT_END_NAMESPACE

namespace GUI
{
class ModelViewWidget : public QWidget
{
    Q_OBJECT

    /*!
         * \brief The columns enum describes the indexes of columns of the table model
         */
    enum columns{
        colTitle=0,
        colDescription,
        colStart,
        colStop,
        colDone
    };

public:
    explicit ModelViewWidget(QWidget *parent = nullptr);

private slots:
    void onRemoveSelectedRowBtnClicked();
private:
    void init();
    void createWidgets();
    void createLayout();
    void createConnections();
    void setViewModelAndFeatures();
    void setDelegates();

private:
    Model::TableModel *m_tableModel{nullptr};
    Delegate::DateTimeDelegate *m_dtDelegate{nullptr};
    Delegate::SpinBoxDelegate *m_spDelegate{nullptr};
    Delegate::TitleDelegate *m_titleDelegate{nullptr};
    Delegate::DescriptionDelegate *m_descDelegate{nullptr};
    QTableView *m_view{nullptr};
    QLabel *m_widgetTitle{nullptr};
    QPushButton *m_addNewRowBtn{nullptr};
    QPushButton *m_removeBtn{nullptr};
};
}


#endif // MODELVIEWWIDGET_H
