#include "DescriptionDelegate.h"


#include <QLineEdit>
#include <QCompleter>
namespace Delegate
{
QWidget *DescriptionDelegate::createEditor(QWidget *parent,
                                           const QStyleOptionViewItem &option,
                                           const QModelIndex &index) const
{
    Q_UNUSED(option)
    Q_UNUSED(index)

    QStringList items;
    items<<"Model View Controller"<<"Database"<<"Qt Widgets"<<"Dialog-based App"<<"Windows-based App"<<"QML";
    items <<"Custom Model"<<"Custom Widget"<<"Layout Management"<<"Multi-Threading"<<"Other";

    auto m_lineEditor = new QLineEdit(parent);

    auto m_completer = new QCompleter(items);
    m_completer->setCaseSensitivity(Qt::CaseInsensitive);
    m_completer->setCompletionMode(QCompleter::UnfilteredPopupCompletion);

    m_lineEditor->setCompleter(m_completer);

    return m_lineEditor;
}

void DescriptionDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{

    auto m_lineEdit = dynamic_cast<QLineEdit*>(editor);
    QString value = index.model()->data(index).toString();
    m_lineEdit->setText(value);
}
//Submitting Data to the Model
void DescriptionDelegate::setModelData(QWidget *editor,
                                       QAbstractItemModel *model,
                                       const QModelIndex &index) const
{


    auto m_line= dynamic_cast<QLineEdit*>(editor);
    QString text = m_line->text();
    model->setData(index,text,Qt::EditRole);
}
}



