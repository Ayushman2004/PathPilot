#ifndef PREPARE_STATEMENT_H
#define PREPARE_STATEMENT_H

#include <string>
#include "statement.h"

PrepareResult prepare_statement(std::string input_buffer, Statement* statement);

#endif // 
