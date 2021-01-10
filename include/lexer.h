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
    DEFAULT,
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
    NAME,
    NUM_KEYWORDS
} Keyword;

typedef enum Symbol {
    ADD,
    SUB,
    MULT,
    DIV,
    MOD,
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
    RIGHT_SHIFT_ASSIGN,
    AND,
    OR,
    BIT_LEFT,
    BIT_RIGHT,
    BIT_AND,
    BIT_OR,
    BIT_NOT,
    BIT_XOR,
    EQUAL,
    LESS,
    GREATER,
    NOT_EQUAL,
    LESS_EQUAL,
    GREATER_EQUAL,
    SINGLE_LINE,
    MULTI_LINE_OPEN,
    MULTI_LINE_CLOSE,
    NUM_SYMBOLS
} Symbol;

// A symbol that does not require a space in front of it
typedef enum SpecialSymbol {
    PERIOD,
    COMMA,
    COLON,
    SEMI_COLON,
    ADDRESS,
    NOT,
    STAR,
    ARROW,
    PARENTHESIS_OPEN,
    PARENTHESIS_CLOSE,
    BRACKET_OPEN,
    BRACKET_CLOSE,
    CURLY_BRACKET_OPEN,
    CURLY_BRACKET_CLOSE,
    NUM_SPECIAL_SYMBOLS
} SpecialSymbol;

static const char *keywords[] = {
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
    [DEFAULT] = "default",
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

static const char *symbols[] = {
    [ADD] = "+",
    [SUB] = "-",
    [MULT] = "*",
    [DIV] = "/",
    [MOD] = "%",
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
    [RIGHT_SHIFT_ASSIGN] = ">>=",
    [AND] = "&&",
    [OR] = "|",
    [BIT_LEFT] = "<<",
    [BIT_RIGHT] = ">>",
    [BIT_AND] = "&",
    [BIT_OR] = "|",
    [BIT_NOT] = "~",
    [BIT_XOR] = "^",
    [EQUAL] = "==",
    [LESS] = "<",
    [GREATER] = ">",
    [NOT_EQUAL] = "!=",
    [LESS_EQUAL] = "<=",
    [GREATER_EQUAL] = ">=",
    [SINGLE_LINE] = "//",
    [MULTI_LINE_OPEN] = "/*",
    [MULTI_LINE_CLOSE] = "*/",
};

static const char specialSymbols[] = {
    [PERIOD] = '.',
    [COMMA] = ',',
    [COLON] = ':',
    [SEMI_COLON] = ';',
    [ADDRESS] = '$', // choosing $ to not confuse with bitwise and
    [NOT] = '!',
    [STAR] = '*',
    [ARROW] = '#',
    [PARENTHESIS_OPEN] = '(',
    [PARENTHESIS_CLOSE] = ')',
    [BRACKET_OPEN] = '[',
    [BRACKET_CLOSE] = ']',
    [CURLY_BRACKET_OPEN] = '{',
    [CURLY_BRACKET_CLOSE] = '}'
};

typedef union TokenType {
    Keyword keyword;
    Symbol symbol;
    SpecialSymbol specialSymbol;
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

Token *lexer();

#endif //MOME_LEXER_H
