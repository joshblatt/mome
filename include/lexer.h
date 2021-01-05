//
// Created by Josh Blatt on 2021-01-03.
//

#ifndef MOME_LEXER_H
#define MOME_LEXER_H

const char *typedef_keyword = "typedef";
const char *enum_keyword = "enum";
const char *struct_keyword = "struct";
const char *union_keyword = "union";
const char *var_keyword = "var";
const char *const_keyword = "const";
const char *func_keyword = "func";
const char *sizeof_keyword = "sizeof";
const char *break_keyword = "break";
const char *continue_keyword = "continue";
const char *return_keyword = "return";
const char *if_keyword = "if";
const char *else_keyword = "else";
const char *while_keyword = "while";
const char *do_keyword = "do";
const char *for_keyword = "for";
const char *switch_keyword = "switch";
const char *case_keyword = "case";
const char *default_keyword = "default";
const char **keywords;

void initKeywords ();

typedef enum Keyword {
    TYPEDEF,
    ENUM,
    STRUCT,
    UNION,
    VAR,
    CONST,
    FUNC,
    SIZEOF,
    BREAK,
    CONTINUE,
    RETURN,
    IF,
    ELSE,
    WHILE,
    DO,
    FOR,
    SWITCH,
    CASE,
    DEFAULT
} Keyword;

typedef enum VarType {
    INT,
    INT8,
    INT16,
    INT32,
    INT64,
    UINT,
    UINT8,
    UINT16,
    UINT32,
    UINT64,
    DOUBLE,
    STRING,
    BOOL,
    CHAR,
    NAME
} VarType;

typedef enum Operator {
    ADD,
    SUB,
    MULT,
    DIV,
    MOD
} Operator;

typedef enum Assignment {
    ASSIGN,
    ADD_ASSIGN,
    SUB_ASSIGN,
    MULT_ASSIGN,
    DIV_ASSIGN,
    MOD_ASSIGN
} Assignment;

typedef enum Punctuation {
    PERIOD,
    COMMA,
    COLON,
    SEMI_COLON
} Punctuation;

typedef enum Location {
    ADDRESS
} Location;

typedef enum LogicalOperator {
    AND,
    OR,
    NOT,
    BIT_AND,
    BIT_OR,
    BIT_NOT,
    BIT_XOR
} LogicalOperator;

typedef enum BitShift {
    BIT_LEFT,
    BIT_RIGHT
} BitShift;

typedef enum Comment {
    SINGLE_LINE,
    MULTI_LINE_OPEN,
    MULTI_LINE_CLOSE
} Comment;

typedef enum Dereference {
    STAR,
    ARROW
} Dereference;

typedef union TokenType {
    Keyword keyword;
    VarType varType;
    Operator operator;
    Assignment assignment;
    Punctuation punctuation;
    Location location;
    LogicalOperator logicalOperator;
    BitShift bitShift;
    Comment comment;
    Dereference dereference;
} TokenType;

typedef union TokenValue {
    int64_t signed_integer;
    uint64_t unsigned_integer;
    double decimal;
    const char *string;
    const char *name;
    bool boolean;
} TokenValue;

typedef struct Token {
    TokenType type;
    TokenValue tokenValue;
};

#endif //MOME_LEXER_H
