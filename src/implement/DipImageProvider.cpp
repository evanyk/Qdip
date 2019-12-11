#include "../include/DipImageProvider.h"

DipImageProvider::DipImageProvider()
    : QQuickImageProvider(QQuickImageProvider::Image)
{
    // Ignore
}

QImage DipImageProvider::requestImage(const QString &id, QSize *size, const QSize &requestedSize)
{
    return this->img;
}

QPixmap DipImageProvider::requestPixmap(const QString &id, QSize *size, const QSize &requestedSize)
{
    return QPixmap::fromImage(this->img);
}
