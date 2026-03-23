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

    // ── 3. Menu principal ──────────────────────────────────────────────────
    vector<string> dbOrdenada;
    bool estaOrdenado = false;
    int algoritmoUsado = 0; // 1=Quick, 2=Heap, 3=AVL
    double tiempoUsado = 0;
    size_t memUsada = 0;

    int menuOpcion = 0;

    do {
        cout << "\n============================================================\n";
        cout << "                     MENU PRINCIPAL                        \n";
        cout << "============================================================\n";
        cout << "  1. Ver dataset (imprimir todas las palabras)\n";
        cout << "  2. Ordenar dataset\n";
        if (estaOrdenado) {
            cout << "  3. Ver estadisticas de ordenamiento\n";
            cout << "  4. Ver complejidad algoritmica\n";
        } else {
            cout << "  3. Ver estadisticas de ordenamiento  [Requiere ordenar primero]\n";
            cout << "  4. Ver complejidad algoritmica       [Requiere ordenar primero]\n";
        }
        cout << "  0. Salir\n";
        cout << "Opcion: ";
        cin >> menuOpcion;
        cout << "\n";

        switch (menuOpcion) {

            // ── Ver dataset ────────────────────────────────────────────────
            case 1: {
                vector<string>& db = estaOrdenado ? dbOrdenada : palabrasOriginal;
                cout << "============================================================\n";
                cout << (estaOrdenado ? "  DATASET ORDENADO\n" : "  DATASET ORIGINAL (sin ordenar)\n");
                cout << "============================================================\n";
                for (int i = 0; i < (int)db.size(); i++)
                    cout << i + 1 << ". " << db[i] << "\n";
                cout << "============================================================\n";
                cout << "Total: " << db.size() << " palabras\n";
                break;
            }

            // ── Ordenar dataset ────────────────────────────────────────────
            case 2: {
                cout << "============================================================\n";
                cout << "         SELECCIONE EL ALGORITMO DE ORDENAMIENTO           \n";
                cout << "============================================================\n";
                cout << "  1. QuickSort\n";
                cout << "  2. HeapSort\n";
                cout << "  3. AVL Tree\n";
                cout << "Opcion: ";
                int algOpcion;
                cin >> algOpcion;
                cout << "\n";

                if (algOpcion == 1) {
                    cout << "Ejecutando QuickSort...\n";
                    dbOrdenada = palabrasOriginal;
                    auto t1 = iniciarTiempo();
                    quickSort(dbOrdenada, 0, (int)dbOrdenada.size() - 1);
                    tiempoUsado = calcularTiempo(t1);
                    memUsada = memoriaVector(dbOrdenada);
                    algoritmoUsado = 1;
                    estaOrdenado = true;
                    cout << "QuickSort completado.\n";
                    cout << "  Tiempo : " << tiempoUsado << " ms\n";
                    cout << "  Memoria aprox: " << memUsada / 1024 << " KB\n";

                } else if (algOpcion == 2) {
                    cout << "Ejecutando HeapSort...\n";
                    dbOrdenada = palabrasOriginal;
                    auto t2 = iniciarTiempo();
                    heapSort(dbOrdenada);
                    tiempoUsado = calcularTiempo(t2);
                    memUsada = memoriaVector(dbOrdenada);
                    algoritmoUsado = 2;
                    estaOrdenado = true;
                    cout << "HeapSort completado.\n";
                    cout << "  Tiempo : " << tiempoUsado << " ms\n";
                    cout << "  Memoria aprox: " << memUsada / 1024 << " KB\n";

                } else if (algOpcion == 3) {
                    cout << "Ejecutando AVL Tree...\n";
                    AVLNode* root = nullptr;
                    auto t3 = iniciarTiempo();
                    for (const string& palabra : palabrasOriginal)
                        root = insertAVL(root, palabra);
                    dbOrdenada.clear();
                    dbOrdenada.reserve(n);
                    inorder(root, dbOrdenada);
                    tiempoUsado = calcularTiempo(t3);
                    memUsada = memoriaAVL(n);
                    deleteTree(root);
                    algoritmoUsado = 3;
                    estaOrdenado = true;
                    cout << "AVL Tree completado.\n";
                    cout << "  Tiempo : " << tiempoUsado << " ms\n";
                    cout << "  Memoria aprox: " << memUsada / 1024 << " KB\n";

                } else {
                    cout << "Opcion invalida.\n";
                }
                break;
            }

            // ── Estadisticas de ordenamiento ───────────────────────────────
            case 3: {
                if (!estaOrdenado) {
                    cout << "Primero debes ordenar el dataset (opcion 2).\n";
                    break;
                }
                string nombreAlgo = (algoritmoUsado == 1) ? "QuickSort" :
                                    (algoritmoUsado == 2) ? "HeapSort"  : "AVL Tree";
                cout << "============================================================\n";
                cout << "            ESTADISTICAS DEL ORDENAMIENTO                  \n";
                cout << "============================================================\n";
                cout << left << setw(15) << "Algoritmo" << setw(15) << "Tiempo (ms)" << setw(15) << "Memoria (KB)" << "\n";
                cout << string(45, '-') << "\n";
                cout << left << setw(15) << nombreAlgo << setw(15) << tiempoUsado << setw(15) << memUsada / 1024 << "\n";
                cout << "============================================================\n";
                break;
            }

            // ── Complejidad algoritmica ────────────────────────────────────
            case 4: {
                if (!estaOrdenado) {
                    cout << "Primero debes ordenar el dataset (opcion 2).\n";
                    break;
                }
                cout << "============================================================\n";
                cout << "              COMPLEJIDAD ALGORITMICA                      \n";
                cout << "============================================================\n";

                if (algoritmoUsado == 1) {
                    cout << "Algoritmo usado: QuickSort\n";
                    analizarArchivo("Ordenamiento/Quick_Sort.cpp");
                } else if (algoritmoUsado == 2) {
                    cout << "Algoritmo usado: HeapSort\n";
                    analizarArchivo("Ordenamiento/Heap_Sort.cpp");
                } else if (algoritmoUsado == 3) {
                    cout << "Algoritmo usado: AVL Tree\n";
                    analizarArchivo("Ordenamiento/AVL_Tree.cpp");
                }

                cout << "============================================================\n";
                break;
            }

            case 0:
                cout << "Saliendo...\n";
                break;

            default:
                cout << "Opcion invalida. Intenta de nuevo.\n";
                break;
        }

    } while (menuOpcion != 0);

    return 0;
}