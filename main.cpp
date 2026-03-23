#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

#include "Funciones_Palabras/Randomizar.h"
#include "Funciones_Palabras/Convertir_txt.h"
#include "Funciones_Palabras/Crear_txt.h"
#include "Ordenamiento/Quick_Sort.h"
#include "Ordenamiento/Heap_Sort.h"
#include "Ordenamiento/AVL_Tree.h"
#include "Recursos/Tiempo.h"
#include "Recursos/Memoria.h"
#include "Recursos/Complejidad.h"

using namespace std;

int main() {

    // ── 1. Seleccion del dataset ───────────────────────────────────────────
    cout << "============================================================\n";
    cout << "         SELECCIONE EL DATASET A UTILIZAR                  \n";
    cout << "============================================================\n";
    cout << "  1. Dataset del profesor (dataset.txt)\n";
    cout << "  2. Dataset generado aleatoriamente (palabras inventadas)\n";
    cout << "Opcion: ";

    int opcion;
    cin >> opcion;
    cout << "\n";

    string archivoDataset = "dataset.txt";

    if (opcion == 2) {
        int cantidad;
        cout << "Cuantas palabras quieres generar? (recomendado: 100000): ";
        cin >> cantidad;

        ofstream archivo(archivoDataset);
        for (int i = 0; i < cantidad; i++)
            archivo << generarPalabra() << "\n";
        archivo.close();

        cout << cantidad << " palabras generadas y guardadas en '" << archivoDataset << "'\n\n";

    } else {
        // Randomizar el dataset del profesor antes de cargar
        cout << "Randomizando dataset...\n";
        randomizarDataset(archivoDataset);
    }

    // ── 2. Cargar las palabras en un vector ────────────────────────────────
    vector<string> palabrasOriginal = cargarDataset(archivoDataset);

    if (palabrasOriginal.empty()) {
        cerr << "Error: no se pudieron cargar las palabras.\n";
        return 1;
    }

    int n = (int)palabrasOriginal.size();
    cout << "Total de palabras cargadas: " << n << "\n\n";

    // ── 3. QuickSort ───────────────────────────────────────────────────────
    cout << "Ejecutando QuickSort...\n";
    vector<string> vecQuick = palabrasOriginal;
    auto t1 = iniciarTiempo();
    quickSort(vecQuick, 0, (int)vecQuick.size() - 1);
    double tiempoQuick = calcularTiempo(t1);
    size_t memQuick = memoriaVector(vecQuick);
    cout << "QuickSort completado.\n";
    cout << "  Tiempo : " << tiempoQuick << " ms\n";
    cout << "  Memoria aprox: " << memQuick / 1024 << " KB\n\n";

    // ── 4. HeapSort ────────────────────────────────────────────────────────
    cout << "Ejecutando HeapSort...\n";
    vector<string> vecHeap = palabrasOriginal;
    auto t2 = iniciarTiempo();
    heapSort(vecHeap);
    double tiempoHeap = calcularTiempo(t2);
    size_t memHeap = memoriaVector(vecHeap);
    cout << "HeapSort completado.\n";
    cout << "  Tiempo : " << tiempoHeap << " ms\n";
    cout << "  Memoria aprox: " << memHeap / 1024 << " KB\n\n";

    // ── 5. AVL Tree ────────────────────────────────────────────────────────
    cout << "Ejecutando AVL Tree...\n";
    AVLNode* root = nullptr;
    auto t3 = iniciarTiempo();
    for (const string& palabra : palabrasOriginal)
        root = insertAVL(root, palabra);
    vector<string> vecAVL;
    vecAVL.reserve(n);
    inorder(root, vecAVL);
    double tiempoAVL = calcularTiempo(t3);
    size_t memAVL = memoriaAVL(n);
    deleteTree(root);
    cout << "AVL Tree completado.\n";
    cout << "  Tiempo : " << tiempoAVL << " ms\n";
    cout << "  Memoria aprox: " << memAVL / 1024 << " KB\n\n";

    // ── 6. Complejidad algoritmica ─────────────────────────────────────────
    mostrarComplejidad();

    // ── 7. Resumen comparativo ─────────────────────────────────────────────
    cout << "============================================================\n";
    cout << "                  RESUMEN COMPARATIVO                      \n";
    cout << "============================================================\n";
    cout << left
         << setw(15) << "Algoritmo"
         << setw(15) << "Tiempo (ms)"
         << setw(15) << "Memoria (KB)" << "\n";
    cout << string(45, '-') << "\n";
    cout << left
         << setw(15) << "QuickSort"
         << setw(15) << tiempoQuick
         << setw(15) << memQuick / 1024 << "\n";
    cout << left
         << setw(15) << "HeapSort"
         << setw(15) << tiempoHeap
         << setw(15) << memHeap / 1024 << "\n";
    cout << left
         << setw(15) << "AVL Tree"
         << setw(15) << tiempoAVL
         << setw(15) << memAVL / 1024 << "\n";
    cout << "============================================================\n";

    return 0;
}
