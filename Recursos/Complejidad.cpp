#include "Complejidad.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Analiza de forma sencilla la complejidad segun ciclos
void analizarArchivo(string nombreArchivo) {
    ifstream archivo(nombreArchivo);
    string linea;

    int nivel = 0;
    int maxNivel = 0;

    while (getline(archivo, linea)) {

        if (linea.find("for") != string::npos || linea.find("while") != string::npos) {
            nivel++;
            if (nivel > maxNivel)
                maxNivel = nivel;
        }

        if (linea.find("}") != string::npos) {
            if (nivel > 0)
                nivel--;
        }
    }

    archivo.close();

    if (maxNivel == 0) cout << "O(1)" << endl;
    else if (maxNivel == 1) cout << "O(n)" << endl;
    else if (maxNivel == 2) cout << "O(n^2)" << endl;
    else cout << "O(n^" << maxNivel << ")" << endl;
}