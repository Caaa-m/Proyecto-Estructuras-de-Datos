#include "Tiempo.h"
#include <iostream>
#include <chrono>
#include <string>
using namespace std;

chrono::high_resolution_clock::time_point inicio;

void iniciarTiempo() {
    inicio = chrono::high_resolution_clock::now(); //uso la librería, y pongo el relog mas preciso disponible en el sistema
}                                                   //Capturo el momento actual y lo guardo en la variable inicio
void detenerTiempo(string etiqueta) {
    auto fin = chrono::high_resolution_clock::now();

    auto ms = chrono::duration_cast<chrono::milliseconds>(fin - inicio).count();
    auto us = chrono::duration_cast<chrono::microseconds>(fin - inicio).count();
    auto ns = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();

    cout << "[ " << etiqueta << " ]" << endl;
    cout << "  Milisegundos : " << ms << " ms" << endl;
    cout << "  Microsegundos: " << us << " us" << endl;
    cout << "  Nanosegundos : " << ns << " ns" << endl;
}