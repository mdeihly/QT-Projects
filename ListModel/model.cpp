#include "model.h"

#include <QColor>

Model::Model(QObject *parent)
    :QAbstractListModel(parent)
{
    list = QColor::colorNames();
}

int Model::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
    {
        return 0;
    }

    return list.size();
}

QVariant Model::data(const QModelIndex &index, int role) const
{
    if(!checkIndex(index, CheckIndexOption::IndexIsValid))
        return QVariant();

    const int row = index.row();
    const QString item = list[row];

    switch (role)
    {
    case Qt::DisplayRole:
        return item;
    case Qt::DecorationRole:
        return QVariant::fromValue(QColor(item));
    }
    return QVariant();
}

QHash<int, QByteArray> Model::roleNames() const
{
    QHash<int, QByteArray> mapping;
    mapping[Qt::DisplayRole] = "display";
    mapping[Qt::DecorationRole] = "decoration";

    return mapping;
}
