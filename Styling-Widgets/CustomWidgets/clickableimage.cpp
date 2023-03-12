#include "clickableimage.h"

#include <QPixmap>

ClickableImage::ClickableImage(QWidget *parent)
    : QLabel(parent)
{
}

void ClickableImage::setImage(const QString &imagePath)
{
    QPixmap pixmap(imagePath);
    setPixmap(pixmap);
    setFixedSize(pixmap.width(), pixmap.height());
}

void ClickableImage::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
        emit clicked();
}
