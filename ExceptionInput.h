#ifndef EXCEPTION_INPUT_H
#define EXCEPTION_INPUT_H

#include "Exception.h"

// Диапазон кодов: 1 - 100
class ExceptionInput : public Exception {
private:
    char badInput[MAX_MSG];

public:
    ExceptionInput(int c, const char* msg, const char* inputStr = "");
    void printError() const override;
};

#endif