#ifndef DATETIMEDELEGATE_H
#define DATETIMEDELEGATE_H

#include <QStyledItemDelegate>

#define DATE_TIME_FORMAT "yyyy-MM-dd HH:mm"

namespace Delegate
{
class DateTimeDelegate : public QStyledItemDelegate
{
public:
    DateTimeDelegate() = default;

    //! This function returns an editor widget
    QWidget *createEditor(QWidget *parent,const QStyleOptionViewItem &option,
                         const QModelIndex &index) const override;

    //! This function reads data from the model (sets data from model to editor)
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;

    //! This function reads the content of the datetimeEdit, and writes it to the model
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const override;
};
}

#endif // DATETIMEDELEGATE_H
