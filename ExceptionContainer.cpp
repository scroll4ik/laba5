#include "ExceptionContainer.h"

ExceptionContainer::ExceptionContainer(int c, const char* msg, int idx)
    : Exception(c, msg), badIndex(idx) {
}

void ExceptionContainer::printError() const {
    Exception::printError(); // Вызов родительского виртуального метода
    if (badIndex != -1) {
        std::cerr << "  -> Invalid index: " << badIndex << std::endl;
    }
}