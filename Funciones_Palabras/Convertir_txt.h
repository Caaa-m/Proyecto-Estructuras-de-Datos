#ifndef CONVERTIR_TXT_H
#define CONVERTIR_TXT_H

#include <vector>
#include <string>
using namespace std;

// Lee el archivo dataset.txt y retorna un vector con todas las palabras.
// Parametro: ruta al archivo (por defecto "dataset.txt")
// Retorna: vector<string> con las palabras cargadas
vector<string> cargarDataset(const string& ruta = "dataset.txt");

#endif
