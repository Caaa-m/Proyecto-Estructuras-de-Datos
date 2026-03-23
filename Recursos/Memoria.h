#pragma once
#include <vector>
#include <string>
#include "AVL_Tree.h"

// Estimacion de memoria para cada estructura de datos

// Memoria aproximada del vector (bytes)
size_t memoriaVector(const std::vector<std::string>& vec);

// Memoria aproximada del AVL Tree (bytes)
size_t memoriaAVL(int nElementos);
