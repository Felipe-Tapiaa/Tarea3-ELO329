#include "GPSFollower.h"
#include <QVBoxLayout>
#include <QStringList>
#include <QDebug>

GPSFollower::GPSFollower(QWidget* parent)
    : QWidget(parent)
{
    QVBoxLayout* layout = new QVBoxLayout(this);

    // Crear escena y vista
    scene = new QGraphicsScene(0, 0, 200, 200);
    view = new QGraphicsView(scene);
    layout->addWidget(view);

    // Crear círculo
    circle = scene->addEllipse(0, 0, 10, 10, QPen(Qt::red), QBrush(Qt::red));

    // Etiqueta con info
    infoLabel = new QLabel("t:0, x:0, y:0");
    layout->addWidget(infoLabel);

    setWindowTitle("Car Tracker");
    resize(250, 300);
    show();
}

void GPSFollower::update(const QString& message)
{
    // Mensaje es "tiempo x y"
    QStringList parts = message.split(" ");
    if (parts.size() >= 3) {
        double t = parts[0].toDouble();
        double x = parts[1].toDouble();
        double y = parts[2].toDouble();

        // Mover círculo
        circle->setRect(x, y, 10, 10);

        // Actualizar texto
        infoLabel->setText(
            QString("t:%1, x:%2, y:%3")
                .arg(t)
                .arg(x)
                .arg(y)
            );

        qDebug() << "Updated position to x:" << x << "y:" << y;
    }
}
