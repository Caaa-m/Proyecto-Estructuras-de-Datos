#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

string generarPalabra() {
    int longitud = rand() % 8 + 3; // entre 3 y 10 letras
    string palabra = "";
    for (int i = 0; i < longitud; i++) {
        char letra = 'a' + rand() % 26;
        palabra += letra;
    }
    return palabra;
}