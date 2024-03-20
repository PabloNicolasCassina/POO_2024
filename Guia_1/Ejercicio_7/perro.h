#ifndef PERRO_H
#define PERRO_H

#include <iostream>
using namespace std;

class Perro
{
public:
    int edad;
    string raza;

    Perro(int edad, string raza);

    Perro();

    void setEdad(int e);
    void setRaza(string r);
    int getEdad() const;
    string getRaza() const;
    bool operator<(const Perro& otro) const;

};


#endif // PERRO_H
