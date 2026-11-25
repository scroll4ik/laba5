#ifndef SAFE_INPUT_H
#define SAFE_INPUT_H

#include <string>
#include "ExceptionInput.h"
using namespace std;

// Вспомогательная проверка и перевод строки в int через stoi (без atoi)
int parseIntStrict(const string& str);

// Только английские ИЛИ только русские буквы (без цифр и символов)
string inputOnlyLetters(const string& prompt);

// Безопасный ввод int (без границ и с границами)
int inputInt(const string& prompt);
int inputInt(const string& prompt, int minVal, int maxVal);

// Безопасный ввод double через stod
double inputDouble(const string& prompt, double minVal, double maxVal);

// Ввод даты в формате DD.MM.YYYY (каждый кусочек проверяется через parseIntStrict)
string inputDate(const string& prompt);

#endif