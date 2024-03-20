#include "perro.h"
#include <iostream>

using namespace std;

int main(){

    Perro p1(5, "Dalmata");
    cout << "La edad del perro 1 es " << p1.getEdad() << " anios" <<endl;
    cout << "La raza del perro 1 es " << p1.getRaza() <<endl;

    Perro p2;

    p2.setEdad(10);
    p2.setRaza("Chihuahua");

    cout << "La edad del perro 2 es " << p2.getEdad() << " anios" <<endl;
    cout << "La raza del perro 2 es " << p2.getRaza() <<endl;
}
