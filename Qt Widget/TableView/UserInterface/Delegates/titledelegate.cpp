#include "TitleDelegate.h"

#include <QComboBox>

namespace Delegate
{

QWidget *TitleDelegate::createEditor(QWidget *parent,
                                     const QStyleOptionViewItem &option,
                                     const QModelIndex &index) const
{
    Q_UNUSED(option)
    Q_UNUSED(index)

    QComboBox *m_comboBoxEditor = new QComboBox(parent);

    m_comboBoxEditor->addItem("Student");
    m_comboBoxEditor->addItem("Intern");
    m_comboBoxEditor->addItem("Junior Consultant");
    m_comboBoxEditor->addItem("Senior Consultant");
    m_comboBoxEditor->addItem("Other");

    return m_comboBoxEditor;
}

void TitleDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{

    QComboBox *m_comboBox = static_cast<QComboBox*>(editor);
    // get the index of the text in the combobox that matches the current value of the item
    const QString currentText = index.data(Qt::EditRole).toString();
    const int cbIndex = m_comboBox->findText(currentText);
    // if it is valid, adjust the combobox
    if(cbIndex>=0)
        m_comboBox->setCurrentIndex(cbIndex);
}
//Submitting Data to the Model
void TitleDelegate::setModelData(QWidget *editor,
                                 QAbstractItemModel *model,
                                 const QModelIndex &index) const
{
    QComboBox *m_cb = static_cast<QComboBox *>(editor);
    QString text = m_cb->currentText();
    model->setData(index,text);

}
}


