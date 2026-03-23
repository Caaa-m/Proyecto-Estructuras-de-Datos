#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "Funciones_Palabras/Randomizar.h"
#include "Funciones_Palabras/Convertir_txt.h"
#include "Funciones_Palabras/Crear_txt.h"
#include "Ordenamiento/Quick_Sort.h"
#include "Ordenamiento/Heap_Sort.h"
#include "Ordenamiento/AVL_Tree.h"
#include "Recursos/Tiempo.h"
#include "Recursos/Memoria.h"

using namespace std;

// Funcion para copiar archivos
void copiarArchivo(string origen, string destino) {
    ifstream in(origen);
    ofstream out(destino);

    string linea;
    while (getline(in, linea)) {
        out << linea << "\n";
    }

    in.close();
    out.close();
}

int main() {

    cout << "   SELECCIONAR DATASET\n";
    cout << "1. Dataset del profesor\n";
    cout << "2. Generar dataset aleatorio\n";
    cout << "Opcion: ";

    int opcion;
    cin >> opcion;

    string archivoTrabajo; // Este es el que siempre usamos

    // Caso 1: Dataset dado por el profesor
    if (opcion == 1) {

        // Copiamos el original a uno temporal
        copiarArchivo("dataset.txt", "dataset_trabajo.txt");
        archivoTrabajo = "dataset_trabajo.txt";

        cout << "Dataset del profesor cargado (copia de trabajo)\n";

        cout << "Deseas mezclarlo? (1=si, 0=no): ";
        int mezclar;
        cin >> mezclar;

        if (mezclar == 1) {
            randomizarDataset(archivoTrabajo);
            cout << "Dataset mezclado\n";
        }
    }

    // Caso 2: Generar dataset aleatorio
    else if (opcion == 2) {

        archivoTrabajo = "dataset_generado.txt";

        int cantidad;
        cout << "Cantidad de palabras: ";
        cin >> cantidad;

        ofstream archivo(archivoTrabajo);

        for (int i = 0; i < cantidad; i++) {
            archivo << generarPalabra() << "\n";
        }

        archivo.close();

        cout << "Dataset generado\n";
    }

    else {
        cout << "Opcion invalida\n";
        return 1;
    }

    // Cargar palabras
    vector<string> palabrasOriginal = cargarDataset(archivoTrabajo);

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

    // Menú
    do {
        cout << "MENU \n";
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
                    TimePoint t = iniciarTiempo();
                    quickSort(dbOrdenada, 0, dbOrdenada.size() - 1);
                    tiempoUsado = calcularTiempo(t);
                    memUsada = memoriaVector(dbOrdenada);
                    algoritmoUsado = 1;
                }
                else if (op == 2) {
                    TimePoint t = iniciarTiempo();
                    heapSort(dbOrdenada);
                    tiempoUsado = calcularTiempo(t);
                    memUsada = memoriaVector(dbOrdenada);
                    algoritmoUsado = 2;
                }
                else if (op == 3) {
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

                cout << "Tiempo: " << tiempoUsado << " ms\n";
                cout << "Memoria aprox: " << memUsada / 1024 << " KB\n";

                break;
            }

            case 3: {
                if (!estaOrdenado) {
                    cout << "Primero ordena el dataset\n";
                    break;
                }

                cout << "Tiempo: " << tiempoUsado << " ms\n";
                cout << "Memoria: " << memUsada / 1024 << " KB\n";
                break;
            }

            case 4: {
                if (!estaOrdenado) {
                    cout << "Primero ordena el dataset\n";
                    break;
                }

                if (algoritmoUsado == 1)
                    cout << "QuickSort: O(n log n)\n";
                else if (algoritmoUsado == 2)
                    cout << "HeapSort: O(n log n)\n";
                else if (algoritmoUsado == 3)
                    cout << "AVL Tree: O(n log n)\n";

                break;
            }

        }

    } while (opcionMenu != 0);

    return 0;
}