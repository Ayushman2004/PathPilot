#include <iostream>
#include <filesystem>
#include "prepare_statement.h"
#include "execute_statement.h"
#include "meta_command.h"
#include "print_prompt.h"
#include "trim_functions.h"

std::string input_buffer;
std::string cur_dir;

int main() {
    cur_dir = std::filesystem::current_path().string();
    while (true) {
        print_promt();
        std::getline(std::cin, input_buffer);
        trim(input_buffer);

        if (input_buffer == "") continue;
        if (input_buffer[0] == '.') {
            switch (do_meta_command(input_buffer)) {
                case META_COMMAND_SUCCESS:
                    continue;
                case META_COMMAND_UNRECOGNIZED_COMMAND:
                    std::cout << "Unrecognized command " << input_buffer << std::endl;
                    continue;
            }
        }

        Statement statement;
        switch (prepare_statement(input_buffer, &statement)) {
            case PREPARE_SUCCESS:
                execute_statement(&statement);
                break;
            case PREPARE_UNRECOGNIZED_STATEMENT:
                std::cout << "Unrecognized statement " << input_buffer << std::endl;
                continue;
        }
    }

    return 0;
}
