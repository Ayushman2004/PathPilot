#include "meta_command.h"
#include "statement.h"
#include <cstring>
#include <cstdlib>

MetaCommandResult do_meta_command(std::string input_buffer) {
    if (strcmp(input_buffer.c_str(), ".exit") == 0) {
        exit(EXIT_SUCCESS);
    } else if (strcmp(input_buffer.c_str(), ".clear") == 0) {
        system("cls");
    } else {
        return META_COMMAND_UNRECOGNIZED_COMMAND;
    }
    return META_COMMAND_SUCCESS;
}
