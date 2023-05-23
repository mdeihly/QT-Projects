#include "customlineedit.h"
#include <QIntValidator>

CustomLineEdit::CustomLineEdit(QWidget *parent)
    : QLineEdit(parent)
{
    QIntValidator *validator = new QIntValidator(this);
    this->setValidator(validator);

    connect(this, &CustomLineEdit::textChanged,
            this, &CustomLineEdit::onTextchanged);
}

void CustomLineEdit::onTextchanged(const QString &newText)
{
    const int num = newText.toInt();
    if(num >= 0 && num <= 75)
    {
        this->setStyleSheet("border: 2px solid gray;");
    }
    else
    {
        this->setStyleSheet("border: 2px solid red");
    }
}
