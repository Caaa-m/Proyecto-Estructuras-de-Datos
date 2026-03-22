#include "Randomizar.h"
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <chrono>
#include <stdexcept>

void randomizarDataset(const std::string& filepath) {

    // ── 1. Leer todas las palabras del dataset ──────────────────────────────
    std::ifstream inFile(filepath);
    if (!inFile.is_open())
        throw std::runtime_error("No se pudo abrir: " + filepath);

    std::vector<std::string> words;
    words.reserve(100000);

    std::string word;
    while (std::getline(inFile, word)) {
        if (!word.empty() && word.back() == '\r')
            word.pop_back();
        if (!word.empty())
            words.push_back(word);
    }
    inFile.close();

    // ── 2. Desordenar aleatoriamente ────────────────────────────────────────
    unsigned seed = static_cast<unsigned>(
        std::chrono::high_resolution_clock::now().time_since_epoch().count()
    );
    std::mt19937 rng(seed);
    std::shuffle(words.begin(), words.end(), rng);

    // ── 3. Sobreescribir el mismo archivo con las palabras desordenadas ─────
    std::ofstream outFile(filepath);
    if (!outFile.is_open())
        throw std::runtime_error("No se pudo escribir en: " + filepath);

    for (const std::string& w : words)
        outFile << w << "\n";

    outFile.close();
}
