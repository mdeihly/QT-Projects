#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include "../DataModel/datamodel.h"
#include <QAbstractTableModel>
#include <QVector>

namespace Model
{
class TableModel : public QAbstractTableModel
{
    Q_OBJECT

    enum Columns
    {
        TitleCol = 0,
        DescriptionCol,
        StartCol,
        StopCol,
        DoneCol,
        ColumnsNumber
    };

public:
    TableModel(QObject *parent= nullptr);
    /**
     * @brief rowCount is used to get the number of rows (list size)
     */
    int rowCount(const QModelIndex &parent) const;
    /**
     * @brief columnCount is used to get the number of columns
     */
    int columnCount(const QModelIndex &parent) const;
    /**
     * @brief data is used to get a specific piece of information about the data to display
     */
    QVariant data(const QModelIndex &index, int role) const;
    /**
     * @brief setData is used to update data
     */
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    /**
     * @brief flags is used to get item flags for the given index.
     */
    Qt::ItemFlags flags(const QModelIndex &index) const;
    /**
     * @brief headerData is used to get the data for the given role and section in the header with the specified orientation.
     */
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    void addRow();
    void removeRow(const QModelIndex & currentIndex);

private:
    QVector<Data::DataModel> m_data;
};
}


#endif // TABLEMODEL_H
