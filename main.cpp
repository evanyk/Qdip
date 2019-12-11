#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlComponent>
#include <opencv2/opencv.hpp>
#include "./src/include/process/ConvertToGrayImage.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    // Register C++ Functions
    ConvertToGrayImage *toGrayImage = new ConvertToGrayImage();

    QQmlContext *context = new QQmlContext(engine.rootContext());
    context->setContextProperty(QLatin1String("ConvertToGrayImage"), toGrayImage);
    engine.addImageProvider(QLatin1String("ImageProvider"), toGrayImage->dipImageProvider);

    const QUrl url(QStringLiteral("qrc:/main.qml"));

    QQmlComponent component(&engine);

    component.loadUrl(url);

    if (component.isReady())
    {
        component.create(context);
    }
//    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
//                     &app, [url](QObject *obj, const QUrl &objUrl) {
//        if (!obj && url == objUrl)
//            QCoreApplication::exit(-1);
//    }, Qt::QueuedConnection);
//    engine.load(url);

    return app.exec();
}
