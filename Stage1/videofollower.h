#ifndef VIDEOFOLLOWER_H
#define VIDEOFOLLOWER_H

#include <QWidget>
#include <QPushButton>
#include "Subscriber.h"

class VideoFollower : public QWidget, public Subscriber {
    Q_OBJECT
private:
    QPushButton* button;
public:
    VideoFollower(QWidget* parent = nullptr);
    void update(const QString& message) override;
};

#endif
