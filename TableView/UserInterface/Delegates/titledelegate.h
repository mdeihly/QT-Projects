#ifndef TITLEDELEGATE_H
#define TITLEDELEGATE_H

#include <QStyledItemDelegate>

namespace Delegate
{
class TitleDelegate : public QStyledItemDelegate
{
public:
    TitleDelegate() = default;

    //! This function returns an editor widget
    QWidget *createEditor(QWidget *parent,const QStyleOptionViewItem &option,
                          const QModelIndex &index) const override;

    //! This function reads data from the model (sets data from model to editor)
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;

    //! This function reads the content of the comboBox, and writes it to the model
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const override;


};
}


#endif // TITLEDELEGATE_H
