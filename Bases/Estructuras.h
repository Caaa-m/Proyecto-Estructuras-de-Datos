#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

#include <string>
using namespace std;

// Estructura de un nodo 
struct Nodo {
    string dato;        // aquí se guarda el valor
    Nodo* siguiente;    // apunta al siguiente nodo
};

// Implementación de una pila 
struct Pila {
    Nodo* tope = nullptr;  // apunta al nodo que está en la cima

    // Agrega un elemento a la pila
    void push(string valor) {
        Nodo* nuevo = new Nodo();   // se crea un nuevo nodo
        nuevo->dato = valor;        // se le asigna el valor
        nuevo->siguiente = tope;    // apunta al antiguo tope
        tope = nuevo;               // ahora el nuevo nodo es el tope
    }

    // Elimina el elemento del tope
    void pop() {
        if (tope == nullptr) return;  // si está vacía no hace nada
        Nodo* temp = tope;            // guardamos el nodo actual
        tope = tope->siguiente;       // movemos el tope al siguiente
        delete temp;                  // liberamos memoria
    }

    // Devuelve el valor del tope
    string top() {
        if (tope == nullptr) return "";  // si está vacía retorna vacío
        return tope->dato;
    }

    // Verifica si la pila está vacía
    bool empty() {
        return tope == nullptr;
    }
};


// Implementación de una cola 
struct Cola {
    Nodo* frente = nullptr;  // primer elemento de la cola
    Nodo* final_ = nullptr;  // último elemento de la cola

    // Agrega un elemento al final
    void enqueue(string valor) {
        Nodo* nuevo = new Nodo();
        nuevo->dato = valor;
        nuevo->siguiente = nullptr;

        // si ya hay elementos, el último apunta al nuevo
        if (final_ != nullptr) final_->siguiente = nuevo;

        final_ = nuevo;  // actualizamos el final

        // si la cola estaba vacía, el frente también es el nuevo
        if (frente == nullptr) frente = nuevo;
    }

    // Elimina el elemento del frente
    void dequeue() {
        if (frente == nullptr) return;  // si está vacía no hace nada
        Nodo* temp = frente;
        frente = frente->siguiente;

        // si después de eliminar queda vacía, también se actualiza el final
        if (frente == nullptr) final_ = nullptr;

        delete temp;
    }

    // Devuelve el valor del frente
    string front() {
        if (frente == nullptr) return "";
        return frente->dato;
    }

    // Verifica si la cola está vacía
    bool empty() {
        return frente == nullptr;
    }
};

#endif