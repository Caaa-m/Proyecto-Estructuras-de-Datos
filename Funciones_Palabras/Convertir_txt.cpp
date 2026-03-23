#include "Convertir_txt.h"
#include <fstream>
#include <iostream>
using namespace std;

// Carga las palabras de un archivo .txt en un vector
vector<string> cargarDataset(const string& ruta) {
    vector<string> palabras;

    ifstream archivo(ruta);

    // Verifica si el archivo se pudo abrir
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        return palabras;
    }

    string palabra;

    // Lee línea por línea
    while (getline(archivo, palabra)) {
        if (!palabra.empty()) {
            palabras.push_back(palabra);
        }
    }

    archivo.close();

    cout << "Se cargaron " << palabras.size() << " palabras" << endl;

    return palabras;
}