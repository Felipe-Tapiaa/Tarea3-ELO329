#include "GPSCarPublisher.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>

GPSCarPublisher::GPSCarPublisher(QWidget* parent)
    : QWidget(parent),
    currentTime(0),
    index(0)
{
    // Layout simple con un rótulo
    QVBoxLayout* layout = new QVBoxLayout(this);
    QLabel* label = new QLabel("GPSCarPublisher activo");
    layout->addWidget(label);

    // Seleccionar archivo
    QString filename = QFileDialog::getOpenFileName(
        this,
        "Seleccionar archivo de posiciones",
        "",
        "Text Files (*.txt *.csv);;All Files (*)"
        );

    if (filename.isEmpty()) {
        qDebug() << "No se seleccionó archivo.";
        return;
    }

    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "No se pudo abrir el archivo.";
        return;
    }

    // Leer todas las líneas
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(" ", Qt::SkipEmptyParts);
        if (parts.size() >= 3) {
            Position pos;
            pos.time = parts[0].toDouble();
            pos.x = parts[1].toDouble();
            pos.y = parts[2].toDouble();
            positions.append(pos);
        }
    }
    file.close();

    if (positions.size() < 2) {
        qDebug() << "Se necesitan al menos dos posiciones para interpolar.";
        return;
    }

    // Iniciar temporizador
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &GPSCarPublisher::updatePosition);
    timer->start(1000); // cada segundo
}

void GPSCarPublisher::updatePosition()
{
    currentTime += 1.0;

    // Verificar que no se pasó del tiempo máximo
    if (currentTime > positions.last().time) {
        timer->stop();
        qDebug() << "Simulación terminada.";
        return;
    }

    // Encontrar segmento actual
    while (index < positions.size() - 2 && currentTime > positions[index + 1].time) {
        index++;
    }

    const Position& p1 = positions[index];
    const Position& p2 = positions[index + 1];

    // Interpolación lineal
    double t = (currentTime - p1.time) / (p2.time - p1.time);
    double x = p1.x + t * (p2.x - p1.x);
    double y = p1.y + t * (p2.y - p1.y);

    QString message = QString("%1 %2 %3")
                          .arg(currentTime)
                          .arg(x)
                          .arg(y);

    notifyAll(message);

    qDebug() << "Enviado:" << message;
}
