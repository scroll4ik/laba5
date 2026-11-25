#include "SafeInput.h"
#include <iostream>
#include <cctype>
#include <stdexcept>

int parseIntStrict(const string& str) {
    if (str.empty()) {
        throw ExceptionInput(1, "Input cannot be empty.", "");
    }
    for (size_t i = 0; i < str.length(); i++) {
        if (i == 0 && (str[i] == '-' || str[i] == '+')) {
            if (str.length() == 1) {
                throw ExceptionInput(4, "Not a valid integer (sign only).", str.c_str());
            }
            continue;
        }
        if (!isdigit(static_cast<unsigned char>(str[i]))) {
            throw ExceptionInput(5, "Integer must contain digits only.", str.c_str());
        }
    }

    try {
        size_t pos = 0;
        int val = stoi(str, &pos);
        if (pos != str.length()) {
            throw ExceptionInput(6, "Extra characters in integer.", str.c_str());
        }
        return val;
    }
    catch (const invalid_argument&) {
        throw ExceptionInput(7, "Failed to parse integer (stoi).", str.c_str());
    }
    catch (const out_of_range&) {
        throw ExceptionInput(8, "Integer is out of type range.", str.c_str());
    }
}

string inputOnlyLetters(const string& prompt) {
    while (true) {
        try {
            cout << prompt;
            string input;
            getline(cin, input);

            if (input.empty()) {
                throw ExceptionInput(1, "Input cannot be empty.", "");
            }

            bool hasEng = false;
            bool hasRus = false;

            for (size_t i = 0; i < input.length(); i++) {
                unsigned char uc = static_cast<unsigned char>(input[i]);
                if ((uc >= 'a' && uc <= 'z') || (uc >= 'A' && uc <= 'Z')) {
                    hasEng = true;
                }
                else if (uc >= 128) {
                    hasRus = true;
                }
                else {
                    throw ExceptionInput(2, "Only letters allowed (no digits, spaces or symbols).", input.c_str());
                }
            }

            if (hasEng && hasRus) {
                throw ExceptionInput(3, "Use only English OR only Russian letters (do not mix).", input.c_str());
            }

            return input;
        }
        catch (const ExceptionInput& e) {
            e.printError();
            cout << "Please try again.\n";
        }
    }
}

int inputInt(const string& prompt) {
    while (true) {
        try {
            cout << prompt;
            string input;
            getline(cin, input);
            return parseIntStrict(input);
        }
        catch (const ExceptionInput& e) {
            e.printError();
            cout << "Please try again.\n";
        }
    }
}

int inputInt(const string& prompt, int minVal, int maxVal) {
    while (true) {
        try {
            cout << prompt;
            string input;
            getline(cin, input);

            int val = parseIntStrict(input);
            if (val < minVal || val > maxVal) {
                throw ExceptionInput(10, "Integer is out of allowed range.", input.c_str());
            }
            return val;
        }
        catch (const ExceptionInput& e) {
            e.printError();
            cout << "Allowed range: [" << minVal << " .. " << maxVal << "]. Try again.\n";
        }
    }
}

double inputDouble(const string& prompt, double minVal, double maxVal) {
    while (true) {
        try {
            cout << prompt;
            string input;
            getline(cin, input);

            if (input.empty()) {
                throw ExceptionInput(1, "Input cannot be empty.", "");
            }

            bool dotFound = false;
            size_t start = (input[0] == '-' || input[0] == '+') ? 1 : 0;
            if (input.length() == start) {
                throw ExceptionInput(4, "Not a valid number.", input.c_str());
            }

            for (size_t i = start; i < input.length(); i++) {
                if (input[i] == '.') {
                    if (dotFound) throw ExceptionInput(9, "Multiple dots in floating number.", input.c_str());
                    dotFound = true;
                }
                else if (!isdigit(static_cast<unsigned char>(input[i]))) {
                    throw ExceptionInput(5, "Number must contain digits and at most one dot.", input.c_str());
                }
            }

            size_t pos = 0;
            double val = stod(input, &pos);
            if (pos != input.length()) {
                throw ExceptionInput(6, "Extra characters in number.", input.c_str());
            }

            if (val < minVal || val > maxVal) {
                throw ExceptionInput(11, "Double value is out of allowed range.", input.c_str());
            }
            return val;
        }
        catch (const invalid_argument&) {
            ExceptionInput(7, "Failed to parse double (stod).", "").printError();
            cout << "Please try again.\n";
        }
        catch (const out_of_range&) {
            ExceptionInput(8, "Double value overflow.", "").printError();
            cout << "Please try again.\n";
        }
        catch (const ExceptionInput& e) {
            e.printError();
            cout << "Please try again.\n";
        }
    }
}

string inputDate(const string& prompt) {
    while (true) {
        try {
            cout << prompt << " (format DD.MM.YYYY): ";
            string input;
            getline(cin, input);

            if (input.length() != 10 || input[2] != '.' || input[5] != '.') {
                throw ExceptionInput(12, "Wrong date format! Required: DD.MM.YYYY", input.c_str());
            }

            string dStr = input.substr(0, 2);
            string mStr = input.substr(3, 2);
            string yStr = input.substr(6, 4);

            if (!isdigit(static_cast<unsigned char>(dStr[0])) ||
                !isdigit(static_cast<unsigned char>(mStr[0])) ||
                !isdigit(static_cast<unsigned char>(yStr[0]))) {
                throw ExceptionInput(13, "Date parts cannot contain signs.", input.c_str());
            }

            int d = parseIntStrict(dStr);
            int m = parseIntStrict(mStr);
            int y = parseIntStrict(yStr);

            if (y < 1900 || y > 2026) throw ExceptionInput(14, "Year must be 1900..2026.", input.c_str());
            if (m < 1 || m > 12) throw ExceptionInput(15, "Month must be 1..12.", input.c_str());

            int maxDays = 31;
            if (m == 4 || m == 6 || m == 9 || m == 11) maxDays = 30;
            else if (m == 2) {
                bool isLeap = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
                maxDays = isLeap ? 29 : 28;
            }

            if (d < 1 || d > maxDays) throw ExceptionInput(16, "Day out of range for month.", input.c_str());

            return input;
        }
        catch (const ExceptionInput& e) {
            e.printError();
            cout << "Please try again.\n";
        }
    }
}