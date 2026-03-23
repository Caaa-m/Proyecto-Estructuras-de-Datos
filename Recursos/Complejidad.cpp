#include "Complejidad.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Analiza de forma sencilla la complejidad leyendo el archivo
void analizarArchivo(string nombreArchivo) {

    ifstream archivo(nombreArchivo);
    string linea;

    int nivel = 0;
    int maxNivel = 0;
    bool tieneRecursion = false;

    while (getline(archivo, linea)) {

        // Detecta ciclos
        if (linea.find("for") != string::npos || linea.find("while") != string::npos) {
            nivel++;
            if (nivel > maxNivel)
                maxNivel = nivel;
        }

        // Detecta cierre de bloque
        if (linea.find("}") != string::npos) {
            if (nivel > 0)
                nivel--;
        }

        // Detecta recursión básica (funciones que se llaman a sí mismas)
        if (linea.find("quickSort") != string::npos ||
            linea.find("insertAVL") != string::npos ||
            linea.find("heapify") != string::npos) {
            tieneRecursion = true;
        }
    }

    archivo.close();

    // Si detecta recursión, asumimos O(n log n)
    if (tieneRecursion) {
        cout << "Complejidad aproximada: O(n log n)" << endl;
        return;
    }

    // Si no hay recursión, usamos niveles de ciclos
    if (maxNivel == 0) cout << "Complejidad: O(1)" << endl;
    else if (maxNivel == 1) cout << "Complejidad: O(n)" << endl;
    else if (maxNivel == 2) cout << "Complejidad: O(n^2)" << endl;
    else cout << "Complejidad: O(n^" << maxNivel << ")" << endl;
}