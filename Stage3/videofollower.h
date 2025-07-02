#ifndef VIDEOFOLLOWER_H
#define VIDEOFOLLOWER_H

#include <QWidget>
#include <QPushButton>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QAudioOutput>
#include <QString>
#include "Subscriber.h"

class VideoFollower : public QWidget, public Subscriber {
    Q_OBJECT

private:
    QPushButton* button;
    QString lastUrl;

public:
    VideoFollower(QWidget* parent = nullptr);
    void update(const QString& message) override;

private slots:
    void playVideo();
};

#endif
