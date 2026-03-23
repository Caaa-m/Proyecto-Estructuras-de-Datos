#pragma once
#include <vector>
#include <string>

// Nodo del AVL Tree
struct AVLNode {
    std::string key;
    AVLNode*    left;
    AVLNode*    right;
    int         height;

    AVLNode(const std::string& k)
        : key(k), left(nullptr), right(nullptr), height(1) {}
};

// Inserta una palabra en el AVL Tree
AVLNode* insertAVL(AVLNode* root, const std::string& key);

// Recorrido inorder: llena el vector con las palabras en orden alfabetico
void inorder(AVLNode* root, std::vector<std::string>& result);

// Libera la memoria del arbol
void deleteTree(AVLNode* root);
