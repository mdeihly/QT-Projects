#ifndef SPINBOX_H
#define SPINBOX_H

#include <QStyledItemDelegate>
namespace Delegate
{
class SpinBoxDelegate : public QStyledItemDelegate
{
public:
    SpinBoxDelegate() = default;

    //! This function returns an editor widget
    QWidget *createEditor(QWidget *parent,const QStyleOptionViewItem &option,
                         const QModelIndex &index) const override;

    //! This function reads data from the model (sets data from model to editor)
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;

    //! This function reads the content of the spinbox, and writes it to the model
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const override;

};
}


#endif // SPINBOX_H
