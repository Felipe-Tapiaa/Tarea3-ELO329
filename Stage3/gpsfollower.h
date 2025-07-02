#ifndef GPSFOLLOWER_H
#define GPSFOLLOWER_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QLabel>
#include "Subscriber.h"

class GPSFollower : public QWidget, public Subscriber {
    Q_OBJECT

private:
    QGraphicsView* view;
    QGraphicsScene* scene;
    QGraphicsEllipseItem* circle;
    QLabel* infoLabel;

public:
    GPSFollower(QWidget* parent = nullptr);
    void update(const QString& message) override;
};

#endif

