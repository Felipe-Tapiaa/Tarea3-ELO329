#ifndef GPSFOLLOWER_H
#define GPSFOLLOWER_H

#include <QWidget>
#include <QLabel>
#include "Subscriber.h"

class GPSFollower : public QWidget, public Subscriber {
    Q_OBJECT

private:
    QLabel* timeLabel;
    QLabel* positionLabel;

public:
    GPSFollower(QWidget* parent = nullptr);
    void update(const QString& message) override;
};

#endif
