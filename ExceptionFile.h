#ifndef EXCEPTION_FILE_H
#define EXCEPTION_FILE_H

#include "Exception.h"

// Диапазон кодов: 101 - 200
class ExceptionFile : public Exception {
private:
    char fileName[MAX_MSG];

public:
    ExceptionFile(int c, const char* msg, const char* fName = "");
    void printError() const override;
};

#endif