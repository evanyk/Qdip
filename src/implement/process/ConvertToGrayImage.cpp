#include "../../include/process/ConvertToGrayImage.h"
#include "opencv2/core.hpp"
#include "opencv2/opencv.hpp"
#include <QUrl>
#include <qdebug.h>
#include <iostream>

ConvertToGrayImage::ConvertToGrayImage(QObject *parent)
    : QObject(parent)
{
    dipImageProvider = new DipImageProvider();
}

void ConvertToGrayImage::openImage(const QString url)
{
    using namespace cv;
    QUrl *u = new QUrl(url);
    std::cout << "url -> " << u->toLocalFile().toStdString() << std::endl;
    Mat srcMat = imread(u->toLocalFile().toStdString());
    QImage tmpImg;
    Mat rgbMat;
    if (srcMat.channels() == 3)
    {
        cvtColor(srcMat, rgbMat, COLOR_BGR2RGB);
        tmpImg = QImage((const unsigned char*)(rgbMat.data),
                        rgbMat.cols, rgbMat.rows,
                        rgbMat.cols * rgbMat.channels(),
                        QImage::Format_RGB888);
    }
    else
    {
        tmpImg = QImage((const unsigned char*)(srcMat.data),
                        srcMat.cols, srcMat.rows,
                        srcMat.cols * srcMat.channels(),
                        QImage::Format_RGB888);
    }

    this->setImage(tmpImg.scaled(400, 300, Qt::KeepAspectRatio));
}

void ConvertToGrayImage::setImage(QImage image)
{
    dipImageProvider->img = image;
    emit callQmlLoadImage();
}
