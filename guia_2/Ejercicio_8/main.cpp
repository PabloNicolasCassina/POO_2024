#include <iostream>
#include <string>

using namespace std;

// Definición de la clase Persona
class Persona {
private:
    string nombre;

public:
    Persona(string nombre) : nombre(nombre) {}

    string getNombre() const {
        return nombre;
    }
};

// Definición de la clase Poste
class Poste {
private:
    double altura;
    double diametro;

public:
    Poste(double altura, double diametro) : altura(altura), diametro(diametro) {}

    double getAltura() const {
        return altura;
    }

    double getDiametro() const {
        return diametro;
    }
};

// Función genérica para imprimir la descripción de cualquier objeto
template <typename T>
void imprimirDescripcion(const T& objeto) {
    cout << "Descripcion: ";
    cout << objeto << endl;
}

// Sobrecarga del operador << para imprimir objetos Persona
ostream& operator<<(ostream& os, const Persona& persona) {
    os << "Persona con nombre " << persona.getNombre();
    return os;
}

// Sobrecarga del operador << para imprimir objetos Poste
ostream& operator<<(ostream& os, const Poste& poste) {
    os << "Poste con altura de " << poste.getAltura() << " metros y "
       << poste.getDiametro() << " cm de diametro";
    return os;
}

int main() {
    // Crear objetos de la clase Persona
    Persona persona1("Lucrecia");
    Persona persona2("Juan");

    // Crear objetos de la clase Poste
    Poste poste1(8.0, 15.0);
    Poste poste2(10.5, 20.0);

    // Probar la función genérica
    imprimirDescripcion(persona1);
    imprimirDescripcion(persona2);
    imprimirDescripcion(poste1);
    imprimirDescripcion(poste2);

    return 0;
}
