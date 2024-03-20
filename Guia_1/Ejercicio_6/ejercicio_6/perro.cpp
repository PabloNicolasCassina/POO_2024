#include "perro.h"
#include <iostream>


using namespace std;

Perro::Perro(int edad, string raza): edad(edad), raza(raza) {}

Perro::Perro() {}

void Perro::setEdad(int e) {
    edad = e;
}

void Perro::setRaza(string r) {
    raza = r;
}

int Perro::getEdad() {
    return edad;
}

string Perro::getRaza() {
    return raza;
}
