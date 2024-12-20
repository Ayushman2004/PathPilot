#include "print_prompt.h"
#include <iostream>
#include <filesystem>

extern std::string cur_dir;

void print_promt() {
    std::cout << cur_dir << ">> ";
}
