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

    // Slider horizontal de volumen (0 - 100)
    volumeSlider = new QSlider(Qt::Horizontal);
    volumeSlider->setRange(0, 100);
    volumeSlider->setValue(80); // volumen inicial
    layout->addWidget(volumeSlider);

    connect(button, &QPushButton::clicked, this, &VideoFollower::playVideo);
}

void VideoFollower::update(const QString& message)
{
    lastUrl = message;
    button->setText(message);
}

void VideoFollower::playVideo()
{
    if (lastUrl.isEmpty())
        return;

    QVideoWidget* videoWidget = new QVideoWidget;
    videoWidget->setAttribute(Qt::WA_DeleteOnClose);

    QMediaPlayer* player = new QMediaPlayer;
    QAudioOutput* audioOutput = new QAudioOutput;
    // Ajustar volumen al valor del slider
    audioOutput->setVolume(volumeSlider->value() / 100.0);

    player->setAudioOutput(audioOutput);
    player->setVideoOutput(videoWidget);

    player->setSource(QUrl(lastUrl));
    player->play();

    videoWidget->resize(800, 600);
    videoWidget->show();

    // Conectar el slider al volumen del audioOutput
    connect(volumeSlider, &QSlider::valueChanged, [audioOutput](int value) {
        audioOutput->setVolume(value / 100.0);
    });
}
