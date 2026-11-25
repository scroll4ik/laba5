#ifndef EXCEPTION_CONTAINER_H
#define EXCEPTION_CONTAINER_H

#include "Exception.h"

// Диапазон кодов: 201 - 300
class ExceptionContainer : public Exception {
private:
    int badIndex;

public:
    ExceptionContainer(int c, const char* msg, int idx = -1);
    void printError() const override;
};

#endif