#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unordered_map>

using namespace std;

int main() {
    vector<int> v1;

    srand(time(nullptr));

    for (int i = 0; i < 30; ++i) {
        int num = rand() % 15 + 1;
        v1.push_back(num);
    }

    // Calcular la moda
    unordered_map<int, int> frecuencia;
    for (int i = 0; i < v1.size(); ++i) {
        frecuencia[v1[i]]++;
    }

    int moda = -1;
    int max_frecuencia = 0;
    for (auto& it : frecuencia) {
        if (it.second > max_frecuencia) {
            moda = it.first;
            max_frecuencia = it.second;
        }
    }

    cout << "Elementos del vector:" << endl;
    for (int i = 0; i < v1.size(); ++i) {
        cout << v1[i] << " ";
    }
    cout << endl;

    cout << "La moda es: " << moda << " (aparece " << max_frecuencia << " veces)" << endl;

    return 0;
}
