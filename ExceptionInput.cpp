#include "ExceptionInput.h"

ExceptionInput::ExceptionInput(int c, const char* msg, const char* inputStr)
    : Exception(c, msg) {
    copyStr(badInput, inputStr, MAX_MSG);
}

void ExceptionInput::printError() const {
    Exception::printError(); // Вызов родительского виртуального метода
    if (badInput[0] != '\0') {
        std::cerr << "  -> Invalid input: '" << badInput << "'" << std::endl;
    }
}