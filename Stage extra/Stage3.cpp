#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "VideoPublisher.h"
#include "VideoFollower.h"
#include "GPSCarPublisher.h"
#include "GPSFollower.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;

    // Layout principal horizontal
    QHBoxLayout* mainLayout = new QHBoxLayout(&window);

    // Layouts verticales
    QVBoxLayout* publishersLayout = new QVBoxLayout();
    QVBoxLayout* subscribersLayout = new QVBoxLayout();

    // Publicadores
    VideoPublisher* videoPublisher = new VideoPublisher;
    GPSCarPublisher* gpsPublisher = new GPSCarPublisher;

    // Suscriptores
    VideoFollower* videoFollower1 = new VideoFollower;
    VideoFollower* videoFollower2 = new VideoFollower;  // Suscriptor extra
    GPSFollower* gpsFollower1 = new GPSFollower;
    GPSFollower* gpsFollower2 = new GPSFollower;        // Suscriptor extra

    // Conectar video
    videoPublisher->addSubscriber(videoFollower1);
    videoPublisher->addSubscriber(videoFollower2);

    // Conectar GPS
    gpsPublisher->addSubscriber(gpsFollower1);
    gpsPublisher->addSubscriber(gpsFollower2);

    // Añadir publicadores al layout izquierdo
    publishersLayout->addWidget(videoPublisher);
    publishersLayout->addWidget(gpsPublisher);

    // Añadir suscriptores al layout derecho
    subscribersLayout->addWidget(videoFollower1);
    subscribersLayout->addWidget(videoFollower2);
    // GPSFollowers abren sus propias ventanas

    // Añadir layouts al layout principal
    mainLayout->addLayout(publishersLayout);
    mainLayout->addLayout(subscribersLayout);

    window.setWindowTitle("Stage Extra - Múltiples Suscriptores y Publicadores");
    window.resize(800, 600);
    videoFollower1->resize(200, 200);

    window.show();

    return app.exec();
}
