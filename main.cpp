#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <direct.h>    // para crear carpeta en Windows
#include "Funciones_Palabras/Crear_txt.h"
#include "Recursos/Complejidad.h"
#include "Recursos/Tiempo.h"
using namespace std;

int main() {
    iniciarTiempo();
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
    detenerTiempo("Creación de un archivo con palabras aleatorias");



    /* string archivo;
    cout << "Nombre del archivo a analizar: ";
    cin >> archivo;

    analizarArchivo(archivo); */
    return 0;
}