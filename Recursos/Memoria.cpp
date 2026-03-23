#include "Memoria.h"
#include <string>
#include <vector>
using namespace std;

// Calcula memoria aproximada del vector
size_t memoriaVector(const vector<string>& vec) {
    size_t total = sizeof(vec);

    for (int i = 0; i < vec.size(); i++) {
        total += sizeof(vec[i]);
    }

    return total;
}

// Estimacion sencilla para AVL
size_t memoriaAVL(int nElementos) {
    return nElementos * sizeof(AVLNode);
}