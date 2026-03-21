#include <iostream>
#include <cstdlib> // Especificamente para usar rand()
#include <ctime>
#include <string>
using namespace std;

string generarPalabra() {
    int longitud = rand() % 8 + 3; // entre 3 y 10 letras
    string palabra = "";
    for (int i = 0; i < longitud; i++) {
        char letra = 'a' + rand() % 26; // letra aleatoria entre 'a' y 'z', rand() % 26 genera un número entre 0 y 25, que se suma a 'a' para obtener una letra
        palabra += letra;
    }
    return palabra;
}