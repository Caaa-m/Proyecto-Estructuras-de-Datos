#include "Heap_Sort.h"
#include <vector>
#include <string>

// Mantiene la propiedad del max-heap desde el nodo i hacia abajo
static void heapify(std::vector<std::string>& arr, int n, int i) {
    int largest = i;       // raiz
    int left    = 2 * i + 1;
    int right   = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(std::vector<std::string>& arr) {
    int n = (int)arr.size();

    // 1. Construir el max-heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // 2. Extraer elementos del heap uno por uno
    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);  // mueve la raiz (mayor) al final
        heapify(arr, i, 0);         // restaura el heap sin el ultimo elemento
    }
}
