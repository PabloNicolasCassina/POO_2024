#include "mapa.h"
#include <QPainter>
#include <QImage>

Mapa::Mapa(QWidget *parent) : QWidget(parent) {
    // Cargar la imagen desde el disco
    imagen.load("C:/UBP/POO_2024/guia_2/ejercicio_12"); // Cambia "ruta/a/tu/imagen.jpg" por la ruta real de tu imagen
}

void Mapa::paintEvent( QPaintEvent * )  {
    QPainter painter(this);
    // Dibujar la imagen en las coordenadas (0, 0) del widget
    painter.drawImage(0, 0, imagen);
}
