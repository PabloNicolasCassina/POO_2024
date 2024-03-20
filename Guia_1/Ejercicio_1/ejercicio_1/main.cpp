#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    // Semilla para generar números aleatorios
    srand(time(nullptr));

    // Vector para almacenar números aleatorios únicos
    vector<int> numeros;

    // Generar 10 números aleatorios únicos en el rango [2, 20]
    while (numeros.size() < 10) {
        int num = rand() % 19 + 2; // Genera números en el rango [2, 20]
        if (find(numeros.begin(), numeros.end(), num) == numeros.end()) {
            numeros.push_back(num);
        }
    }

    // Mostrar los números generados
    cout << "Los 10 numeros aleatorios en el intervalo [2, 20] son:\n";
    for (int num : numeros) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
