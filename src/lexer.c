//
// Created by Josh Blatt on 2021-01-03.
//

#include "../include/lexer.h"

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