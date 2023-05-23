#include "SpinBoxDelegate.h"

#include <QSpinBox>

namespace Delegate
{
QWidget *SpinBoxDelegate::createEditor(QWidget *parent,
                                       const QStyleOptionViewItem &option,
                                       const QModelIndex &index) const
{
    Q_UNUSED(option)
    Q_UNUSED(index)

    QSpinBox *m_spinBoxEditor = new QSpinBox(parent);
    m_spinBoxEditor->setRange(0,100);
    m_spinBoxEditor->setSingleStep(5);
    m_spinBoxEditor->setSuffix(" %");
    m_spinBoxEditor->setWrapping(true);

    return m_spinBoxEditor;
}

void SpinBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    int value = index.model()->data(index,Qt::EditRole).toInt();
    QSpinBox *m_spinBox = static_cast<QSpinBox*>(editor);
    m_spinBox->setValue(value);
}
//Submitting Data to the Model
void SpinBoxDelegate::setModelData(QWidget *editor,
                                   QAbstractItemModel *model,
                                   const QModelIndex &index) const
{
    QSpinBox *m_spinBoxModel = static_cast<QSpinBox*>(editor);

    int value = m_spinBoxModel->value();
    model->setData(index,value,Qt::EditRole);

}
}


