#include "Heap_Sort.h"
#include <vector>
#include <string>
using namespace std;

// Ajusta el heap
void heapify(vector<string>& arr, int n, int i) {
    int mayor = i;
    int izq = 2 * i + 1;
    int der = 2 * i + 2;

    if (izq < n && arr[izq] > arr[mayor])
        mayor = izq;

    if (der < n && arr[der] > arr[mayor])
        mayor = der;

    if (mayor != i) {
        swap(arr[i], arr[mayor]);
        heapify(arr, n, mayor);
    }
}

// HeapSort
void heapSort(vector<string>& arr) {
    int n = arr.size();

    // Construir heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Ordenar
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}