#include "Convertir_txt.h"
#include <fstream>
#include <iostream>
using namespace std;
 
vector<string> cargarDataset(const string& ruta) {
    vector<string> palabras;  // aquí se van a guardar las palabras del archivo
 
    ifstream archivo(ruta);   // se abre el archivo en modo lectura
 
    // Verifica si el archivo se abrió correctamente
    if (!archivo.is_open()) {
        cout<< "Error: no se pudo abrir el archivo '" << ruta << "'" << endl;
        return palabras; // retorna vector vacio si hay error
    }
 
    string palabra;
    
    // Lee el archivo linea por linea
    while (getline(archivo, palabra)) {
        // Ignora lineas vacias
        if (!palabra.empty()) {
            palabras.push_back(palabra);  // guarda la palabra en el vector
        }
    }
 
    archivo.close(); // cierra el archivo
 
    // Mensaje para confirmar cuantas palabras se cargaron
    cout << "Dataset cargado: " << palabras.size() 
         << " palabras desde '" << ruta << "'" << endl;
 
    return palabras;  // retorna el vector con todas las palabras
}