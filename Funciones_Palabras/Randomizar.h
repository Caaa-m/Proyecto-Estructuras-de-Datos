#pragma once
#include <string>

// Lee dataset.txt, desordena las palabras aleatoriamente
// y sobreescribe el mismo archivo con el nuevo orden.
// Lanza std::runtime_error si el archivo no se puede abrir.
void randomizarDataset(const std::string& filepath);