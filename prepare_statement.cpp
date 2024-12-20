#include "prepare_statement.h"
#include <cstring>

PrepareResult prepare_statement(std::string input_buffer, Statement* statement) {
    if (strncmp(input_buffer.c_str(), "select", 6) == 0) {
        statement->type = STATEMENT_SELECT;
        return PREPARE_SUCCESS;
    }
    if (strncmp(input_buffer.c_str(), "show", 4) == 0) {
        statement->type = STATEMENT_SHOW;
        return PREPARE_SUCCESS;
    }
    if (strncmp(input_buffer.c_str(), "back", 4) == 0) {
        statement->type = STATEMENT_BACK;
        return PREPARE_SUCCESS;
    }
    return PREPARE_UNRECOGNIZED_STATEMENT;
}
