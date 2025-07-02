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
    VideoFollower* videoFollower = new VideoFollower;
    GPSFollower* gpsFollower = new GPSFollower;

    // Conectar suscriptores a publicadores
    videoPublisher->addSubscriber(videoFollower);
    gpsPublisher->addSubscriber(gpsFollower);

    // Añadir publicadores al layout izquierdo
    publishersLayout->addWidget(videoPublisher);
    publishersLayout->addWidget(gpsPublisher);

    // Añadir suscriptores al layout derecho
    subscribersLayout->addWidget(videoFollower);
    // gpsFollower no se añade aquí porque abre su propia ventana

    // Añadir layouts a layout principal
    mainLayout->addLayout(publishersLayout);
    mainLayout->addLayout(subscribersLayout);

    window.setWindowTitle("Stage 4 - Simulador Completo");
    window.resize(800, 400);
    window.show();

    return app.exec();
}
