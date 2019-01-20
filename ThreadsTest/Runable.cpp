#include "Runable.h"

bool Runable::isRunned() {
    return m_runned;
}

void Runable::run() {
    m_runned = true;
}
