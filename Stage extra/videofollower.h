#ifndef VIDEOFOLLOWER_H
#define VIDEOFOLLOWER_H

#include <QWidget>
#include <QPushButton>
#include <QSlider>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QAudioOutput>
#include "Subscriber.h"

class VideoFollower : public QWidget, public Subscriber {
    Q_OBJECT

private:
    QPushButton* button;
    QSlider* volumeSlider;
    QString lastUrl;

public:
    VideoFollower(QWidget* parent = nullptr);
    void update(const QString& message) override;

private slots:
    void playVideo();
    void changeVolume(int value);
};

#endif
