#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <direct.h>    // para crear carpeta en Windows
#include "Funciones_Palabras/Crear_txt.h"
using namespace std;

int main() {
    srand(time(0));

    string nombreCarpeta;
    cout << "Nombre de la carpeta: ";
    cin >> nombreCarpeta;

    _mkdir(nombreCarpeta.c_str());  // crea la carpeta

    int cantidad;
    cout << "Cuantas palabras quieres generar? ";
    cin >> cantidad;

    string ruta = nombreCarpeta + "/palabras.txt";
    ofstream archivo(ruta);

    for (int i = 0; i < cantidad; i++) {
        archivo << generarPalabra() << endl;
    }

    archivo.close();
    cout << "Archivo guardado en: " << ruta << endl;

    return 0;
}