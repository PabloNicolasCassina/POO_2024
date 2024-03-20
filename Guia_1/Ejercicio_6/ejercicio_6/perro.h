#ifndef PERRO_H
#define PERRO_H

#include <iostream>
using namespace std;

class Perro
{
    int edad;
    string raza;
public:
    Perro(int edad, string raza);

    Perro();

    void setEdad(int e);
    void setRaza(string r);
    int getEdad();
    string getRaza();
};


#endif // PERRO_H
