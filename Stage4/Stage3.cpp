#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include "GPSCarPublisher.h"
#include "GPSFollower.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    QHBoxLayout* layout = new QHBoxLayout(&window);

    GPSCarPublisher* publisher = new GPSCarPublisher;
    GPSFollower* follower = new GPSFollower;

    publisher->addSubscriber(follower);

    layout->addWidget(publisher);

    window.setWindowTitle("Stage 3 - GPS Publisher & Follower");
    window.resize(400, 150);
    window.show();

    return app.exec();
}
