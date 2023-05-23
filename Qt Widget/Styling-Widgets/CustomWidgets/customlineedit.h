#ifndef CUSTOMLINEEDIT_H
#define CUSTOMLINEEDIT_H

#include <QLineEdit>

class CustomLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit CustomLineEdit(QWidget *parent = nullptr);
    ~CustomLineEdit() = default;

private slots:
    void onTextchanged(const QString &newText);
};

#endif // CUSTOMLINEEDIT_H
