#include "ExceptionFile.h"

ExceptionFile::ExceptionFile(int c, const char* msg, const char* fName)
    : Exception(c, msg) {
    copyStr(fileName, fName, MAX_MSG);
}

void ExceptionFile::printError() const {
    Exception::printError(); // Вызов родительского виртуального метода
    if (fileName[0] != '\0') {
        std::cerr << "  -> File name: '" << fileName << "'" << std::endl;
    }
}