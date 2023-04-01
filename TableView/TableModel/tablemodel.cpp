#include "tablemodel.h"

namespace Model
{
TableModel::TableModel(QObject *parent):
    QAbstractTableModel(parent)
{
}

int TableModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
    {
        return 0;
    }

    return m_data.size();
}

int TableModel::columnCount(const QModelIndex &parent) const
{
    if(parent.isValid())
    {
        return 0;
    }

    return Columns::ColumnsNumber;
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if(!checkIndex(index, CheckIndexOption::IndexIsValid))
        return QVariant();

    const int row = index.row();
    const int col = index.column();

    const Data::DataModel &item = m_data[row];

    if(Qt::DisplayRole == role)
    {
        switch (col)
        {
        case TitleCol:
            return item.getTitle();
        case DescriptionCol:
            return item.getDescription();
        case StartCol:
            return item.getStart();
        case StopCol:
            return item.getStop();
        case DoneCol:
            return item.getDone();
        }
    }

    return QVariant();
}

bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!checkIndex(index, CheckIndexOption::IndexIsValid))
        return false;

    const int row = index.row();
    const int col = index.column();

    Data::DataModel &item = m_data[row];

    switch (col)
    {
    case TitleCol:
    {
        QString modifiedTitle = value.toString(); // set data to your backend
        item.setTitle(modifiedTitle);
        break;
    }
    case DescriptionCol:
    {
        QString modifiedDescription = value.toString();
        item.setDescription(modifiedDescription);
        break;
    }
    case StartCol:
    {
        QDateTime modifiedStart= value.toDateTime();
        item.setStart(modifiedStart);
        break;
    }
    case StopCol:
    {
        QDateTime modifiedStop = value.toDateTime();
        item.setStop(modifiedStop);
        break;
    }
    case DoneCol:
    {
        int modifiedDone=value.toInt();
        item.setDone(modifiedDone);
        break;
    }
    default:
        Q_ASSERT(false);
    }

    //dataChanged() signal to notify whoever is interested that a ..
    //row changed for the given indexes (the start index and end index)
    emit dataChanged(index, index);

    return true;
}

Qt::ItemFlags TableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (Qt::DisplayRole != role)
        return QVariant();

    // Horizontal Header
    if (Qt::Horizontal == orientation)
    {
        // The section parameter is the column number (Horizontal orientation)
        switch (section)
        {
        case Columns::TitleCol:
            return QString("Title");
        case Columns::DescriptionCol:
            return QString("Description");
        case Columns::StartCol:
            return QString("Start");
        case Columns::StopCol:
            return QString("Stop");
        case Columns::DoneCol:
            return QString("% Done");
        }
    }
    else if(Qt::Vertical  == orientation)
        return  QString("Day %1").arg(section+1);
}

void TableModel::addRow()
{
    int position = m_data.size();

    beginInsertRows(QModelIndex(),position,position);

    m_data.insert(position,Data::DataModel()); // it specifies the position and the value to be inserted
    endInsertRows();
}

void TableModel::removeRow(const QModelIndex &currentIndex)
{
    if(!checkIndex(currentIndex, CheckIndexOption::IndexIsValid))
    {
        return;
    }

    int position = currentIndex.row();

    beginRemoveRows(QModelIndex(),position,position);

    m_data.removeAt(position);

    endRemoveRows();
}
}


