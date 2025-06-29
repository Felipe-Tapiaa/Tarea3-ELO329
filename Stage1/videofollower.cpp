#include "VideoFollower.h"
#include <QVBoxLayout>

VideoFollower::VideoFollower(QWidget* parent)
    : QWidget(parent)
{
    QVBoxLayout* layout = new QVBoxLayout(this);

    button = new QPushButton("No video yet");
    layout->addWidget(button);
}

void VideoFollower::update(const QString& message) {
    button->setText(message);
}
