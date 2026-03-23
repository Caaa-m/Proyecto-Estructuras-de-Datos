#include "Quick_Sort.h"
#include <vector>
#include <string>
using namespace std;

// Funcion para dividir el arreglo usando el ultimo elemento como pivote
int partition(vector<string>& arr, int low, int high) {
    string pivot = arr[high]; // pivote
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// QuickSort recursivo
void quickSort(vector<string>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}