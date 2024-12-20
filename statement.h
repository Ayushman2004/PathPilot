#ifndef STATEMENT_H
#define STATEMENT_H

enum StatementType {
    STATEMENT_SELECT,
    STATEMENT_SHOW,
    STATEMENT_BACK
};

class Statement {
    public:
    StatementType type;
};

enum MetaCommandResult{ 
    META_COMMAND_SUCCESS, 
    META_COMMAND_UNRECOGNIZED_COMMAND 
};

enum PrepareResult {
    PREPARE_SUCCESS,
    PREPARE_UNRECOGNIZED_STATEMENT
};

#endif 
