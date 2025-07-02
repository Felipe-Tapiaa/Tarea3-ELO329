#include "GPSFollower.h"
#include <QVBoxLayout>
#include <QStringList>

GPSFollower::GPSFollower(QWidget* parent)
    : QWidget(parent)
{
    QVBoxLayout* layout = new QVBoxLayout(this);

    timeLabel = new QLabel("Tiempo: 0");
    positionLabel = new QLabel("Posición: (0, 0)");

    layout->addWidget(timeLabel);
    layout->addWidget(positionLabel);

    setWindowTitle("GPS Follower");
    resize(300, 100);
    show();
}

void GPSFollower::update(const QString& message)
{
    // El mensaje es: "tiempo x y"
    QStringList parts = message.split(" ");
    if (parts.size() >= 3) {
        double tiempo = parts[0].toDouble();
        double x = parts[1].toDouble();
        double y = parts[2].toDouble();

        timeLabel->setText(QString("Tiempo: %1").arg(tiempo));
        positionLabel->setText(QString("Posición: (%1, %2)").arg(x).arg(y));
    }
}
