#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include "VideoPublisher.h"
#include "VideoFollower.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    QHBoxLayout* layout = new QHBoxLayout(&window);

    VideoPublisher* publisher = new VideoPublisher;
    VideoFollower* subscriber = new VideoFollower;

    publisher->addSubscriber(subscriber);

    layout->addWidget(publisher);
    layout->addWidget(subscriber);

    window.setWindowTitle("Stage 1 - Video Publisher & Follower");
    window.resize(600, 200);
    window.show();

    return app.exec();
}
