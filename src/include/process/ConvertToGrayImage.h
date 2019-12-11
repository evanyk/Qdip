#ifndef CONVERTTOGRAYIMAGE_H
#define CONVERTTOGRAYIMAGE_H

#include <QObject>
#include "../DipImageProvider.h"

class ConvertToGrayImage: public QObject
{
    Q_OBJECT
public:
    explicit ConvertToGrayImage(QObject *parent = 0);
    DipImageProvider *dipImageProvider;
    Q_INVOKABLE void openImage(const QString url);
public slots:
    void setImage(QImage image);
signals:
    void callQmlLoadImage();
};

#endif // CONVERTTOGRAYIMAGE_H
