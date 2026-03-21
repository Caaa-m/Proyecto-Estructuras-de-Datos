#include "Complejidad.h"
#include <iostream>
#include <fstream> //Abrir, leer, escribir archivos
#include <string>
using namespace std;

void analizarArchivo(string nombreArchivo) {
    ifstream archivo(nombreArchivo); //Lee el archivo
    string linea;

    int nivelActual = 0; //Nivel de anidación actual
    int maxNivel = 0; //Máximo nivel de anidación encontrado

    while (getline(archivo, linea)) { //Lee una Línea del archivo y la guarda en Línea
                                      //Mientras haya una línea más por recorrer devuelve TRUE, si no devuelve FALSE
        if (linea.find("for") != string::npos || linea.find("while") != string::npos) { // Si se encuentra un while o for...
            nivelActual++; // Incrementa el nivel de anidación actual
            if (nivelActual > maxNivel) {
                maxNivel = nivelActual; // Actualiza el máximo nivel de anidación si el actual es mayor
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