#include "jugador.h"

Jugador::Jugador(int velocidad, int fuerza, std::string nombre)
    : velocidad(velocidad), fuerza(fuerza), nombre(nombre) {}

Jugador::~Jugador() {}

void Jugador::setVelocidad(int velocidad) {
    this->velocidad = velocidad;
}

int Jugador::getVelocidad() const {
    return velocidad;
}

void Jugador::setFuerza(int fuerza) {
    this->fuerza = fuerza;
}

int Jugador::getFuerza() const {
    return fuerza;
}

void Jugador::setNombre(const std::string& nombre) {
    this->nombre = nombre;
}

std::string Jugador::getNombre() const {
    return nombre;
}
