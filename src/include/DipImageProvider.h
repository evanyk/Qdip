#ifndef DIPIMAGEPROVIDER_H
#define DIPIMAGEPROVIDER_H


#include <QQuickImageProvider>

class DipImageProvider: public QQuickImageProvider
{
public:
    DipImageProvider();

    QImage img;

    QImage requestImage(const QString &id, QSize *size, const QSize &requestedSize) override;
    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize) override;
};

#endif // DIPIMAGEPROVIDER_H
