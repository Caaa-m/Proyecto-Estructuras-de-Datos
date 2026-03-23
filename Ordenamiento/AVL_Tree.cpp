#include "AVL_Tree.h"
#include <algorithm>
#include <vector>
#include <string>

// ── Utilidades internas ────────────────────────────────────────────────────

static int height(AVLNode* n) {
    return n ? n->height : 0;
}

static int getBalance(AVLNode* n) {
    return n ? height(n->left) - height(n->right) : 0;
}

static void updateHeight(AVLNode* n) {
    if (n)
        n->height = 1 + std::max(height(n->left), height(n->right));
}

// ── Rotaciones ─────────────────────────────────────────────────────────────

static AVLNode* rotateRight(AVLNode* y) {
    AVLNode* x  = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left  = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

static AVLNode* rotateLeft(AVLNode* x) {
    AVLNode* y  = x->right;
    AVLNode* T2 = y->left;

    y->left  = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

// ── Insercion con balanceo automatico ─────────────────────────────────────

AVLNode* insertAVL(AVLNode* root, const std::string& key) {
    // 1. Insercion BST normal
    if (!root)
        return new AVLNode(key);

    if (key < root->key)
        root->left  = insertAVL(root->left,  key);
    else if (key > root->key)
        root->right = insertAVL(root->right, key);
    else
        return root; // duplicados ignorados

    // 2. Actualizar altura
    updateHeight(root);

    // 3. Calcular balance y aplicar rotaciones si es necesario
    int balance = getBalance(root);

    // Caso Left-Left
    if (balance > 1 && key < root->left->key)
        return rotateRight(root);

    // Caso Right-Right
    if (balance < -1 && key > root->right->key)
        return rotateLeft(root);

    // Caso Left-Right
    if (balance > 1 && key > root->left->key) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // Caso Right-Left
    if (balance < -1 && key < root->right->key) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

// ── Recorrido inorder ──────────────────────────────────────────────────────

void inorder(AVLNode* root, std::vector<std::string>& result) {
    if (!root) return;
    inorder(root->left,  result);
    result.push_back(root->key);
    inorder(root->right, result);
}

// ── Liberar memoria ────────────────────────────────────────────────────────

void deleteTree(AVLNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}
