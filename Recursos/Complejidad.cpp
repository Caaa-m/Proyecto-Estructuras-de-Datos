#include "Complejidad.h"
#include <iostream>
#include <iomanip>
using namespace std;

void mostrarComplejidad() {
    cout << "\n";
    cout << "============================================================\n";
    cout << "         ANALISIS DE COMPLEJIDAD ALGORITMICA (Big-O)        \n";
    cout << "============================================================\n";
    cout << left
         << setw(20) << "Algoritmo"
         << setw(15) << "Mejor caso"
         << setw(15) << "Caso promedio"
         << setw(15) << "Peor caso"
         << setw(15) << "Memoria"
         << "\n";
    cout << string(80, '-') << "\n";
    cout << left
         << setw(20) << "QuickSort"
         << setw(15) << "O(n log n)"
         << setw(15) << "O(n log n)"
         << setw(15) << "O(n^2)"
         << setw(15) << "O(log n)"
         << "\n";
    cout << left
         << setw(20) << "HeapSort"
         << setw(15) << "O(n log n)"
         << setw(15) << "O(n log n)"
         << setw(15) << "O(n log n)"
         << setw(15) << "O(1)"
         << "\n";
    cout << left
         << setw(20) << "AVL Tree"
         << setw(15) << "O(n log n)"
         << setw(15) << "O(n log n)"
         << setw(15) << "O(n log n)"
         << setw(15) << "O(n)"
         << "\n";
    cout << string(80, '-') << "\n";
    cout << "\nNotas:\n";
    cout << "  - QuickSort: peor caso ocurre con pivote siempre maximo/minimo.\n";
    cout << "               Con pivote central el peor caso es poco probable.\n";
    cout << "  - HeapSort:  garantiza O(n log n) siempre. Memoria in-place O(1).\n";
    cout << "  - AVL Tree:  arbol balanceado garantiza O(log n) por insercion.\n";
    cout << "               El recorrido inorder es O(n). Memoria O(n) por nodos.\n";
    cout << "============================================================\n\n";
}
