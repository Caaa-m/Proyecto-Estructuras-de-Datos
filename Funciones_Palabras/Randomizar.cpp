#include "Randomizar.h"
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

// Desordena las palabras de un archivo
void randomizarDataset(const string& filepath) {

    ifstream inFile(filepath);

    // Verifica si se pudo abrir
    if (!inFile.is_open()) {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    vector<string> words;
    string word;

    // Leer todas las palabras
    while (getline(inFile, word)) {
        if (!word.empty())
            words.push_back(word);
    }

    inFile.close();

    // Inicializar semilla
    srand(time(0));

    // Mezclar manualmente
    for (int i = 0; i < words.size(); i++) {
        int j = rand() % words.size();
        swap(words[i], words[j]);
    }

    // Sobrescribir archivo
    ofstream outFile(filepath);

    if (!outFile.is_open()) {
        cout << "No se pudo escribir en el archivo" << endl;
        return;
    }

    for (int i = 0; i < words.size(); i++) {
        outFile << words[i] << "\n";
    }

    outFile.close();
}