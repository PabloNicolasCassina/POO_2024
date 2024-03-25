#include <iostream>
#include <vector>
#include "jugador.h"

int main() {
    std::vector<Jugador> jugadores;

    for (int i = 1; i <= 10; ++i) {
        Jugador jugador(i * 5, i * 10, "Jugador " + std::to_string(i));
        jugadores.push_back(jugador);
    }

    for (const auto& jugador : jugadores) {
        std::cout << "Nombre: " << jugador.getNombre() << ", Velocidad: " << jugador.getVelocidad()
                  << ", Fuerza: " << jugador.getFuerza() << std::endl;
    }

    return 0;
}
