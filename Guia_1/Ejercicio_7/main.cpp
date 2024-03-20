#include <iostream>
#include <vector>
#include <algorithm>
#include "perro.h"

using namespace std;

int main() {
    Perro p1(5, "Dalmata");
    Perro p2(3, "Labrador");
    Perro p3(7, "Chihuahua");

    vector<Perro> perros;
    perros.push_back(p1);
    perros.push_back(p2);
    perros.push_back(p3);

    sort(perros.begin(), perros.end());

    cout << "Perros ordenados por edad de menor a mayor:" << endl;
    for (const auto& perro : perros) {
        cout << "Edad: " << perro.getEdad() << ", Raza: " << perro.getRaza() << endl;
    }

    return 0;
}
