#include "Complejidad.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void analizarArchivo(string nombreArchivo) {
    ifstream archivo(nombreArchivo);
    string linea;

    int nivelActual = 0;
    int maxNivel = 0;

    while (getline(archivo, linea)) {
        if (linea.find("for") != string::npos || linea.find("while") != string::npos) {
            nivelActual++;
            if (nivelActual > maxNivel) {
                maxNivel = nivelActual;
            }
        }

        if (linea.find("}") != string::npos) {
            if (nivelActual > 0) nivelActual--;
        }
    }

    archivo.close();

    if (maxNivel == 0) cout << "Complejidad: O(1)" << endl;
    else if (maxNivel == 1) cout << "Complejidad: O(n)" << endl;
    else if (maxNivel == 2) cout << "Complejidad: O(n^2)" << endl;
    else if (maxNivel == 3) cout << "Complejidad: O(n^3)" << endl;
    else cout << "Complejidad: O(n^" << maxNivel << ")" << endl;
}