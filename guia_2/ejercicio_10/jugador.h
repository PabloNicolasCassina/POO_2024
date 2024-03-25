#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>

class Jugador {
private:
    int velocidad;
    int fuerza;
    std::string nombre;

public:
    Jugador(int velocidad = 0, int fuerza = 0, std::string nombre = "sin nombre");

    ~Jugador();

    void setVelocidad(int velocidad);
    int getVelocidad() const;

    void setFuerza(int fuerza);
    int getFuerza() const;

    void setNombre(const std::string& nombre);
    std::string getNombre() const;
};

#endif // JUGADOR_H
