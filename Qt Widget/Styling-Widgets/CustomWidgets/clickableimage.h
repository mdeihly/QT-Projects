#ifndef CLICKABLEIMAGE_H
#define CLICKABLEIMAGE_H

#include <QLabel>
#include <QMouseEvent>

class ClickableImage : public QLabel
{
    Q_OBJECT

public:
    explicit ClickableImage(QWidget* parent = nullptr);
    ~ClickableImage() = default;

    void setImage(const QString &imagePath);

signals:
    void clicked();

    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
};

#endif // CLICKABLEIMAGE_H
