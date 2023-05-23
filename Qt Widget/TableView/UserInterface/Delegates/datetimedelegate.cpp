#include "DateTimeDelegate.h"

#include <QDateTimeEdit>

namespace Delegate
{
QWidget *DateTimeDelegate::createEditor(QWidget *parent,
                                        const QStyleOptionViewItem &option,
                                        const QModelIndex &index) const
{
    Q_UNUSED(option)
    Q_UNUSED(index)

    auto m_dateTimeEditor = new QDateTimeEdit(parent);

    m_dateTimeEditor->setCalendarPopup(true);
    m_dateTimeEditor->setMinimumDateTime(QDateTime::currentDateTime());
    m_dateTimeEditor->setDisplayFormat(DATE_TIME_FORMAT);

    return m_dateTimeEditor;
}

void DateTimeDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{

    auto m_dateTimeEdit = dynamic_cast<QDateTimeEdit*>(editor);
    m_dateTimeEdit->setDateTime(QDateTime::fromString(index.model()->data(index,Qt::EditRole).toString(),DATE_TIME_FORMAT));

}

//Submitting Data to the Model
void DateTimeDelegate::setModelData(QWidget *editor,
                                    QAbstractItemModel *model,
                                    const QModelIndex &index) const
{
    auto m_dateTimeModel = dynamic_cast<QDateTimeEdit*>(editor);

    QString datetime = m_dateTimeModel->dateTime().toString(DATE_TIME_FORMAT);
    model->setData(index,datetime,Qt::EditRole);

}
}

