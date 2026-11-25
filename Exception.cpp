#include "Exception.h"

void Exception::copyStr(char* dest, const char* src, int maxLen) {
    int i = 0;
    if (src != nullptr) {
        while (i < maxLen - 1 && src[i] != '\0') {
            dest[i] = src[i];
            i++;
        }
    }
    dest[i] = '\0';
}

Exception::Exception(int c, const char* msg) : code(c) {
    copyStr(message, msg, MAX_MSG);
}

void Exception::printError() const {
    std::cerr << "[ERROR CODE " << code << "]: " << message << std::endl;
}

int Exception::getCode() const {
    return code;
}