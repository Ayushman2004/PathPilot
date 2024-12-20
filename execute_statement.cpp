#include "execute_statement.h"
#include "trim_functions.h"
#include "directory_exists.h"
#include <iostream>
#include <filesystem>

extern std::string input_buffer;
extern std::string cur_dir;

void execute_statement(Statement* statement) {
    std::string temp;
    switch (statement->type) {
        case STATEMENT_SELECT:
            input_buffer = input_buffer.substr(6);
            frontTrim(input_buffer);
            temp = cur_dir + "\\" + input_buffer;
            if (directoryExists(temp)) cur_dir = temp;
            else std::cout << "Directory did not exist" << std::endl;
            break;
        case STATEMENT_SHOW:
            temp = "dir " + cur_dir;
            system(temp.c_str());
            break;
        case STATEMENT_BACK:
            trimtilBslash(cur_dir);
            break;
    }
}
