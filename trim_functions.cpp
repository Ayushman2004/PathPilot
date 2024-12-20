#include "trim_functions.h"

void frontTrim(std::string& str) {
    size_t firstNonSpace = str.find_first_not_of(' ');
    if (firstNonSpace == std::string::npos) {
        str = "";
        return;
    }
    str = str.substr(firstNonSpace);
}

void trimtilBslash(std::string& str) {
    size_t pos = str.rfind('\\');
    if (pos != std::string::npos) {
        str = str.substr(0, pos);
    }
}

void trim(std::string& str) {
    size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos) {
        str = "";
        return;
    }
    size_t last = str.find_last_not_of(' ');
    str = str.substr(first, (last - first + 1));
}
