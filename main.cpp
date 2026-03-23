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

    cout << "====================================\n";
    cout << "   SELECCIONAR DATASET\n";
    cout << "====================================\n";
    cout << "1. Usar dataset existente\n";
    cout << "2. Generar dataset aleatorio\n";
    cout << "Opcion: ";

    int opcion;
    cin >> opcion;

    string archivoDataset = "dataset.txt";

    // Generar o randomizar
    if (opcion == 2) {
        int cantidad;
        cout << "Cantidad de palabras: ";
        cin >> cantidad;

        ofstream archivo(archivoDataset);

        for (int i = 0; i < cantidad; i++) {
            archivo << generarPalabra() << "\n";
        }

        archivo.close();
        cout << "Dataset generado.\n";

    } else {
        cout << "Mezclando dataset...\n";
        randomizarDataset(archivoDataset);
    }

    // Cargar palabras
    vector<string> palabrasOriginal = cargarDataset(archivoDataset);

    if (palabrasOriginal.empty()) {
        cout << "Error cargando datos\n";
        return 1;
    }

    vector<string> dbOrdenada;
    bool estaOrdenado = false;
    int algoritmoUsado = 0;
    double tiempoUsado = 0;
    size_t memUsada = 0;

    int opcionMenu;

    do {
        cout << "\n======== MENU ========\n";
        cout << "1. Ver dataset\n";
        cout << "2. Ordenar dataset\n";
        cout << "3. Ver estadisticas\n";
        cout << "4. Ver complejidad\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcionMenu;

        switch (opcionMenu) {

            case 1: {
                vector<string>& db = estaOrdenado ? dbOrdenada : palabrasOriginal;

                for (int i = 0; i < db.size(); i++) {
                    cout << db[i] << "\n";
                }

                cout << "Total: " << db.size() << "\n";
                break;
            }

            case 2: {
                cout << "1. QuickSort\n2. HeapSort\n3. AVL\nOpcion: ";
                int op;
                cin >> op;

                dbOrdenada = palabrasOriginal;

                if (op == 1) {
                    cout << "Ordenando con QuickSort...\n";
                    TimePoint t = iniciarTiempo();
                    quickSort(dbOrdenada, 0, dbOrdenada.size() - 1);
                    tiempoUsado = calcularTiempo(t);
                    memUsada = memoriaVector(dbOrdenada);
                    algoritmoUsado = 1;

                } else if (op == 2) {
                    cout << "Ordenando con HeapSort...\n";
                    TimePoint t = iniciarTiempo();
                    heapSort(dbOrdenada);
                    tiempoUsado = calcularTiempo(t);
                    memUsada = memoriaVector(dbOrdenada);
                    algoritmoUsado = 2;

                } else if (op == 3) {
                    cout << "Ordenando con AVL...\n";
                    AVLNode* root = nullptr;

                    TimePoint t = iniciarTiempo();

                    for (int i = 0; i < palabrasOriginal.size(); i++) {
                        root = insertAVL(root, palabrasOriginal[i]);
                    }

                    dbOrdenada.clear();
                    inorder(root, dbOrdenada);

                    tiempoUsado = calcularTiempo(t);
                    memUsada = memoriaAVL(palabrasOriginal.size());

                    deleteTree(root);
                    algoritmoUsado = 3;
                }

                estaOrdenado = true;

                cout << "Tiempo: " << tiempoUsado << " s\n";
                cout << "Memoria aprox: " << memUsada / 1024 << " KB\n";

                break;
            }

            case 3: {
                if (!estaOrdenado) {
                    cout << "Primero ordena el dataset\n";
                    break;
                }

                cout << "Tiempo: " << tiempoUsado << "\n";
                cout << "Memoria: " << memUsada / 1024 << " KB\n";
                break;
            }

            case 4: {
                if (!estaOrdenado) {
                    cout << "Primero ordena el dataset\n";
                    break;
                }

                if (algoritmoUsado == 1)
                    analizarArchivo("Ordenamiento/Quick_Sort.cpp");
                else if (algoritmoUsado == 2)
                    analizarArchivo("Ordenamiento/Heap_Sort.cpp");
                else
                    analizarArchivo("Ordenamiento/AVL_Tree.cpp");

                break;
            }

        }

    } while (opcionMenu != 0);

    return 0;
}