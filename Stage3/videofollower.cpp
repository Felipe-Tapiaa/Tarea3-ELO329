#include "VideoFollower.h"
#include <QVBoxLayout>
#include <QUrl>
#include <QDebug>

VideoFollower::VideoFollower(QWidget* parent)
    : QWidget(parent)
{
    QVBoxLayout* layout = new QVBoxLayout(this);

    button = new QPushButton("No video yet");
    layout->addWidget(button);

    connect(button, &QPushButton::clicked, this, &VideoFollower::playVideo);
}

void VideoFollower::update(const QString& message) {
    lastUrl = message;
    button->setText(message);
}

void VideoFollower::playVideo() {
    qDebug() << "playVideo() called. URL:" << lastUrl;

    if (lastUrl.isEmpty())
        return;

    QVideoWidget* videoWidget = new QVideoWidget;
    videoWidget->setAttribute(Qt::WA_DeleteOnClose);

    QMediaPlayer* player = new QMediaPlayer;
    QAudioOutput* audioOutput = new QAudioOutput;
    audioOutput->setVolume(0.8);

    player->setAudioOutput(audioOutput);
    player->setVideoOutput(videoWidget);

    player->setSource(QUrl(lastUrl));
    player->play();

    videoWidget->resize(800, 600);
    videoWidget->show();
}
