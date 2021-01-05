//
// Created by Josh Blatt on 2021-01-03.
//

#ifndef MOME_LEXER_H
#define MOME_LEXER_H

#include <stdbool.h>
#include <stdlib.h>

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
    MOD_ASSIGN,
    AND_ASSIGN,
    OR_ASSIGN,
    XOR_ASSIGN,
    LEFT_SHIFT_ASSIGN,
    RIGHT_SHIFT_ASSIGN
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
} LogicalOperator;

typedef enum BitOperator {
    BIT_LEFT,
    BIT_RIGHT,
    BIT_AND,
    BIT_OR,
    BIT_NOT,
    BIT_XOR
} BitOperator;

typedef enum RelationalOperator {
    EQUAL,
    LESS,
    GREATER,
    NOT_EQUAL,
    LESS_EQUAL,
    GREATER_EQUAL
} RelationalOperator;

typedef enum Comment {
    SINGLE_LINE,
    MULTI_LINE_OPEN,
    MULTI_LINE_CLOSE
} Comment;

typedef enum Dereference {
    STAR,
    ARROW
} Dereference;

typedef enum Bracket {
    PARENTHESIS_OPEN,
    PARENTHESIS_CLOSE,
    BRACKET_OPEN,
    BRACKET_CLOSE,
    CURLY_BRACKET_OPEN,
    CURLY_BRACKET_CLOSE
} Bracket;

typedef union TokenType {
    Keyword keyword;
    VarType varType;
    Operator operator;
    Assignment assignment;
    Punctuation punctuation;
    Location location;
    LogicalOperator logicalOperator;
    BitOperator bitOperator;
    RelationalOperator relationalOperator;
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
} Token;

const char *keywords[] = {
    [TYPEDEF] = "typedef",
    [ENUM] = "enum",
    [STRUCT] = "struct",
    [UNION] = "union",
    [VAR] = "var",
    [CONST] = "const",
    [FUNC] = "func",
    [SIZEOF] = "sizeof",
    [BREAK] = "break",
    [CONTINUE] = "continue",
    [RETURN] = "return",
    [IF] = "if",
    [ELSE] = "else",
    [WHILE] = "while",
    [DO] = "do",
    [FOR] = "for",
    [SWITCH] = "switch",
    [CASE] = "case",
    [DEFAULT] = "default"
};

const char *varTypes[] = {
    [INT] = "int",
    [INT8] = "int8",
    [INT16] = "int16",
    [INT32] = "int32",
    [INT64] = "int64",
    [UINT] = "uint",
    [UINT8] = "uint8",
    [UINT16] = "uint16",
    [UINT32] = "uint32",
    [UINT64] = "uint64",
    [DOUBLE] = "double",
    [STRING] = "string",
    [BOOL] = "bool",
    [CHAR] = "char",
    [NAME] = "name"
};

const char *operators[] = {
    [ADD] = "+",
    [SUB] = "-",
    [MULT] = "*",
    [DIV] = "/",
    [MOD] = "%"
};

const char *assignments[] = {
    [ASSIGN] = "=",
    [ADD_ASSIGN] = "+=",
    [SUB_ASSIGN] = "-=",
    [MULT_ASSIGN] = "*=",
    [DIV_ASSIGN] = "/=",
    [MOD_ASSIGN] = "%/",
    [AND_ASSIGN] = "&=",
    [OR_ASSIGN] = "|=",
    [XOR_ASSIGN] = "^=",
    [LEFT_SHIFT_ASSIGN] = "<<=",
    [RIGHT_SHIFT_ASSIGN] = ">>="
};

const char *punctuations[] = {
    [PERIOD] = ".",
    [COMMA] = ",",
    [COLON] = ":",
    [SEMI_COLON] = ";"
};

const char *locations[] = {
    [ADDRESS] = "&"
};

const char *logicalOperators[] = {
    [AND] = "&&",
    [OR] = "|",
    [NOT] = "!",
};

const char *bitOperators[] = {
    [BIT_LEFT] = "<<",
    [BIT_RIGHT] = ">>",
    [BIT_AND] = "&",
    [BIT_OR] = "|",
    [BIT_NOT] = "~",
    [BIT_XOR] = "^"
};

const char *relationalOperators[] = {
    [EQUAL] = "==",
    [LESS] = "<",
    [GREATER] = ">",
    [NOT_EQUAL] = "!=",
    [LESS_EQUAL] = "<=",
    [GREATER_EQUAL] = ">="
};

const char *comments[] = {
    [SINGLE_LINE] = "//",
    [MULTI_LINE_OPEN] = "/*",
    [MULTI_LINE_CLOSE] = "*/"
};

const char *deferences[] = {
    [STAR] = "*",
    [ARROW] = "->"
};

const char *brackets[] = {
    [PARENTHESIS_OPEN] = "(",
    [PARENTHESIS_CLOSE] = ")",
    [BRACKET_OPEN] = "[",
    [BRACKET_CLOSE] = "]",
    [CURLY_BRACKET_OPEN] = "{",
    [CURLY_BRACKET_CLOSE] = "}"
};

#endif //MOME_LEXER_H
