#include "AVL_Tree.h"
#include <algorithm>
using namespace std;

// Devuelve la altura del nodo (si es null, es 0)
int height(AVLNode* n) {
    if (n == nullptr) return 0;
    return n->height;
}

// Calcula el balance (izquierda - derecha)
int getBalance(AVLNode* n) {
    if (n == nullptr) return 0;
    return height(n->left) - height(n->right);
}

// Actualiza la altura del nodo
void updateHeight(AVLNode* n) {
    if (n != nullptr) {
        n->height = 1 + max(height(n->left), height(n->right));
    }
}

// Rotación simple a la derecha
AVLNode* rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* temp = x->right;

    x->right = y;
    y->left = temp;

    updateHeight(y);
    updateHeight(x);

    return x;
}

// Rotación simple a la izquierda
AVLNode* rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* temp = y->left;

    y->left = x;
    x->right = temp;

    updateHeight(x);
    updateHeight(y);

    return y;
}

// Inserta en el árbol AVL (como BST pero balanceando)
AVLNode* insertAVL(AVLNode* root, const string& key) {

    // Inserción normal tipo árbol binario
    if (root == nullptr)
        return new AVLNode(key);

    if (key < root->key)
        root->left = insertAVL(root->left, key);
    else if (key > root->key)
        root->right = insertAVL(root->right, key);
    else
        return root; // si es igual, no lo inserta

    // Actualizar altura
    updateHeight(root);

    // Ver si se desbalanceó
    int balance = getBalance(root);

    // Caso izquierda-izquierda
    if (balance > 1 && key < root->left->key)
        return rotateRight(root);

    // Caso derecha-derecha
    if (balance < -1 && key > root->right->key)
        return rotateLeft(root);

    // Caso izquierda-derecha
    if (balance > 1 && key > root->left->key) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // Caso derecha-izquierda
    if (balance < -1 && key < root->right->key) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

// Recorrido inorder (sirve para obtener ordenado)
void inorder(AVLNode* root, vector<string>& result) {
    if (root == nullptr) return;

    inorder(root->left, result);
    result.push_back(root->key);
    inorder(root->right, result);
}

// Libera la memoria del árbol
void deleteTree(AVLNode* root) {
    if (root == nullptr) return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}