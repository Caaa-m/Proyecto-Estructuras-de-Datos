#pragma once
#include <chrono>

// Utilidades para medir tiempo de ejecucion con std::chrono

using Clock     = std::chrono::high_resolution_clock;
using TimePoint = std::chrono::time_point<Clock>;

// Retorna el instante actual
TimePoint iniciarTiempo();

// Retorna los milisegundos transcurridos desde 'inicio'
double calcularTiempo(const TimePoint& inicio);
