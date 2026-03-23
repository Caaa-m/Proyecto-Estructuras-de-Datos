#include "Tiempo.h"

TimePoint iniciarTiempo() {
    return Clock::now();
}

double calcularTiempo(const TimePoint& inicio) {
    auto fin = Clock::now();
    return std::chrono::duration<double, std::milli>(fin - inicio).count();
}
