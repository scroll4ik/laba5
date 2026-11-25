#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>

#define MAX_MSG 80

class Exception {
protected:
    int code;
    char message[MAX_MSG];
    void copyStr(char* dest, const char* src, int maxLen);

public:
    Exception(int c, const char* msg);
    virtual ~Exception() {}

    virtual void printError() const;
    int getCode() const;
};

#endif