#include "modelviewwidget.h"
#include <QTableView>
#include <QHeaderView>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>

namespace GUI
{
ModelViewWidget::ModelViewWidget(QWidget *parent)
    : QWidget{parent}
{
    init();
}

void ModelViewWidget::onRemoveSelectedRowBtnClicked()
{
    QModelIndexList selected_rows = m_view->selectionModel()->selectedRows();

    // if no row is selected
    if(selected_rows.isEmpty())
        return;

    // at least one entire row selected
    if(!selected_rows.isEmpty())
    {

        for(auto selectedRows : selected_rows)
        {
            m_tableModel->removeRow(selectedRows);
        }
    }
}

void ModelViewWidget::init()
{
    createWidgets();
    setViewModelAndFeatures();
    setDelegates();
    createLayout();
    createConnections();
}

void ModelViewWidget::createWidgets()
{
    m_tableModel = new Model::TableModel(this);
    m_dtDelegate = new Delegate::DateTimeDelegate;
    m_spDelegate = new Delegate::SpinBoxDelegate;
    m_titleDelegate = new Delegate::TitleDelegate;
    m_descDelegate = new Delegate::DescriptionDelegate;
    m_view = new QTableView(this);
    m_widgetTitle = new QLabel("TABLE VIEW");
    m_widgetTitle->setStyleSheet("QLabel { font-weight: bold; color:red; }");
    m_addNewRowBtn = new QPushButton("Add Row");
    m_removeBtn = new QPushButton ("Remove Selected Row");
    m_removeBtn->setEnabled(false);
}

void ModelViewWidget::createLayout()
{
    auto layout = new QGridLayout;
    layout->addWidget(m_widgetTitle, 0, 0, 1, 2, Qt::AlignCenter);
    layout->addWidget(m_addNewRowBtn, 1, 0);
    layout->addWidget(m_removeBtn, 1, 1);
    layout->addWidget(m_view, 2, 0, 1, 2);

    setLayout(layout);
}

void ModelViewWidget::createConnections()
{
    connect(m_addNewRowBtn, &QPushButton::clicked,
            [this]()
    {
        if(false == m_removeBtn->isEnabled())
        {
            m_removeBtn->setEnabled(true);
        }
        m_tableModel->addRow();
    });

    connect(m_removeBtn, &QPushButton::clicked,
            this, &ModelViewWidget::onRemoveSelectedRowBtnClicked);
}

void ModelViewWidget::setViewModelAndFeatures()
{
    Q_ASSERT(m_view);
    Q_ASSERT(m_tableModel);

    // set model
    m_view->setModel(m_tableModel);

    m_view->setSortingEnabled(true);
    m_view->setAlternatingRowColors(true);
    m_view->horizontalHeader()->setSectionsMovable(true);
    m_view->horizontalHeader()->setSortIndicatorShown(true);
    m_view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    m_view->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    m_view->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_view->setSelectionMode(QAbstractItemView::SingleSelection);
}

void ModelViewWidget::setDelegates()
{
    Q_ASSERT(m_view);

    // set item delegate
    m_view->setItemDelegateForColumn(colTitle, m_titleDelegate);
    m_view->setItemDelegateForColumn(colDescription, m_descDelegate);
    m_view->setItemDelegateForColumn(colStart, m_dtDelegate);
    m_view->setItemDelegateForColumn(colStop, m_dtDelegate);
    m_view->setItemDelegateForColumn(colDone, m_spDelegate);

}
}

