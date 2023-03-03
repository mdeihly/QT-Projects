#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>

class Calculator : public QWidget
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator() = default;

private slots:
    void onButtonClicked(const QString &newText);
     void setText(const QString &newText);
     void removeDigit();

signals:
  void textChanged(const QString &text);

private:
    void init();
    void createWidgets();
    void createLayout();
    void createConnections();

private:
    QPushButton *m_button0{nullptr};
    QPushButton *m_button1{nullptr};
    QPushButton *m_button2{nullptr};
    QPushButton *m_button3{nullptr};
    QPushButton *m_button4{nullptr};
    QPushButton *m_button5{nullptr};
    QPushButton *m_button6{nullptr};
    QPushButton *m_button7{nullptr};
    QPushButton *m_button8{nullptr};
    QPushButton *m_button9{nullptr};
    QPushButton *m_buttonDot{nullptr};
    QPushButton *m_buttonCancel{nullptr};
    QPushButton *m_buttonClear{nullptr};

    QLineEdit *m_lineEdit{nullptr};

    QString text{""};

};
#endif // CALCULATOR_H
