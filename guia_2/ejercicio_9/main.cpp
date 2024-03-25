#include <iostream>

using namespace std;

template <class T>
void imprimir(T *v, int cantidad, bool mayor_a_menor) {

    for (int i = 1; i < cantidad; ++i) {
        T clave = v[i];
        int j = i - 1;
        while (j >= 0 && ((mayor_a_menor && v[j] < clave) || (!mayor_a_menor && v[j] > clave))) {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = clave;
    }


    cout << "Valores ordenados ";
    if (mayor_a_menor)
        cout << "de mayor a menor: ";
    else
        cout << "de menor a mayor: ";

    for (int i = 0; i < cantidad; ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    int arrInt[] = {5, 2, 7, 1, 9};
    float arrFloat[] = {3.5, 1.2, 6.7, 2.1, 8.9};


    imprimir(arrInt, 5, true);
    imprimir(arrFloat, 5, true);


    imprimir(arrInt, 5, false);
    imprimir(arrFloat, 5, false);

    return 0;
}
