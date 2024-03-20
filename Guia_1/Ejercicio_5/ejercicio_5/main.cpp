#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Para std::sort

int main() {
    std::vector<std::string> expresiones_idiomaticas;

    expresiones_idiomaticas.push_back("A caballo regalado no se le miran los dientes");
    expresiones_idiomaticas.push_back("Mas vale pajaro en mano que cien volando");
    expresiones_idiomaticas.push_back("Cosecharas lo que siembras");
    expresiones_idiomaticas.push_back("El que las hace las paga");
    expresiones_idiomaticas.push_back("Mejor prevenir que curar");

    std::sort(expresiones_idiomaticas.begin(), expresiones_idiomaticas.end());

    std::cout << "Expresiones idiomaticas ordenadas alfabeticamente:" << std::endl;
    for (const std::string& expresion : expresiones_idiomaticas) {
        std::cout << expresion << std::endl;
    }

    return 0;
}
