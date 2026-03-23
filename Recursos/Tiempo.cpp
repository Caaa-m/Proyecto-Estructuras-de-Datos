#include "Tiempo.h"
#include <chrono>
using namespace std;

TimePoint iniciarTiempo() {
    return Clock::now();
}

double calcularTiempo(const TimePoint& inicio) {
    TimePoint fin = Clock::now();
    return chrono::duration<double>(fin - inicio).count();
}