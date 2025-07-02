#ifndef GPSCARPUBLISHER_H
#define GPSCARPUBLISHER_H

#include <QWidget>
#include <QTimer>
#include <QVector>
#include "Publisher.h"

// Estructura auxiliar para almacenar cada posición con su tiempo
struct Position {
    double time; // en segundos
    double x;
    double y;
};

class GPSCarPublisher : public QWidget, public Publisher {
    Q_OBJECT

private:
    QVector<Position> positions; // lista de posiciones del archivo
    QTimer* timer;
    double currentTime; // tiempo transcurrido en segundos
    int index; // índice actual en positions[]

public:
    GPSCarPublisher(QWidget* parent = nullptr);

private slots:
    void updatePosition();
};

#endif
