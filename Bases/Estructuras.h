#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

#include <string>
using namespace std;

struct Nodo {
    string dato;
    Nodo* siguiente;
};

struct Pila {
    Nodo* tope = nullptr;

    void push(string valor) {
        Nodo* nuevo = new Nodo();
        nuevo->dato = valor;
        nuevo->siguiente = tope;
        tope = nuevo;
    }

    void pop() {
        if (tope == nullptr) return;
        Nodo* temp = tope;
        tope = tope->siguiente;
        delete temp;
    }

    string top() {
        if (tope == nullptr) return "";
        return tope->dato;
    }

    bool empty() {
        return tope == nullptr;
    }
};


struct Cola {
    Nodo* frente = nullptr;
    Nodo* final_ = nullptr;

    void enqueue(string valor) {
        Nodo* nuevo = new Nodo();
        nuevo->dato = valor;
        nuevo->siguiente = nullptr;
        if (final_ != nullptr) final_->siguiente = nuevo;
        final_ = nuevo;
        if (frente == nullptr) frente = nuevo;
    }

    void dequeue() {
        if (frente == nullptr) return;
        Nodo* temp = frente;
        frente = frente->siguiente;
        if (frente == nullptr) final_ = nullptr;
        delete temp;
    }

    string front() {
        if (frente == nullptr) return "";
        return frente->dato;
    }

    bool empty() {
        return frente == nullptr;
    }
};

#endif