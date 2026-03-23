#include "Memoria.h"
#include <string>
#include <vector>

// Calcula el tamano aproximado del vector en bytes:
// sizeof(string) por cada elemento + el contenido de cada string
size_t memoriaVector(const std::vector<std::string>& vec) {
    size_t total = sizeof(std::vector<std::string>);
    for (const auto& s : vec) {
        total += sizeof(std::string) + s.capacity();
    }
    return total;
}

// Calcula el tamano aproximado del AVL Tree en bytes:
// Cada nodo tiene: string key + 2 punteros + 1 int height
// Se estima un promedio de 7 caracteres por palabra
size_t memoriaAVL(int nElementos) {
    size_t porNodo = sizeof(AVLNode) + 7; // 7 = promedio de chars por palabra
    return porNodo * (size_t)nElementos;
}
