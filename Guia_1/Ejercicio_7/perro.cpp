#include "perro.h"

using namespace std;

Perro::Perro(int edad, string raza) : edad(edad), raza(raza) {}

Perro::Perro() {}

void Perro::setEdad(int e) {
    edad = e;
}

void Perro::setRaza(string r) {
    raza = r;
}

int Perro::getEdad() const{
    return edad;
}

string Perro::getRaza() const{
    return raza;
}

bool Perro::operator<(const Perro& otro) const {
    return edad < otro.edad;
}


