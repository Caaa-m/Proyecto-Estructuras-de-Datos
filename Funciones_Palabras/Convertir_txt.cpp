#include "Convertir_txt.h"
#include <fstream>
#include <iostream>
using namespace std;

vector<string> cargarDataset(const string& ruta) {
    vector<string> palabras;

    ifstream archivo(ruta);

    if (!archivo.is_open()) {
        cerr << "Error: no se pudo abrir el archivo '" << ruta << "'" << endl;
        return palabras; // retorna vector vacio
    }

    string palabra;
    while (getline(archivo, palabra)) {
        // Ignora lineas vacias
        if (!palabra.empty()) {
            palabras.push_back(palabra);
        }
    }

    archivo.close();

    cout << "Dataset cargado: " << palabras.size() << " palabras desde '" << ruta << "'" << endl;

    return palabras;
}
