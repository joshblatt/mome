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

typedef enum TokenKind {
    TOKEN_EOF = 0,
    // Reserve first 128 values for one-char tokens
    TOKEN_LAST_CHAR = 127,
    TOKEN_KEYWORD,
    TOKEN_INT,
    TOKEN_FLOAT,
    TOKEN_STR,
    TOKEN_NAME,
    TOKEN_LSHIFT,
    TOKEN_RSHIFT,
    TOKEN_EQ,
    TOKEN_NOTEQ,
    TOKEN_LTEQ,
    TOKEN_GTEQ,
    TOKEN_AND,
    TOKEN_OR,
    TOKEN_INC,
    TOKEN_DEC,
    TOKEN_COLON_ASSIGN,
    TOKEN_ADD_ASSIGN,
    TOKEN_FIRST_ASSIGN = TOKEN_ADD_ASSIGN,
    TOKEN_SUB_ASSIGN,
    TOKEN_OR_ASSIGN,
    TOKEN_AND_ASSIGN,
    TOKEN_XOR_ASSIGN,
    TOKEN_LSHIFT_ASSIGN,
    TOKEN_RSHIFT_ASSIGN,
    TOKEN_MUL_ASSIGN,
    TOKEN_DIV_ASSIGN,
    TOKEN_MOD_ASSIGN,
    TOKEN_LAST_ASSIGN = TOKEN_MOD_ASSIGN,
} TokenKind;

typedef enum TokenMode {
    TOKENMODE_NONE,
    TOKENMODE_HEX,
    TOKENMODE_BIN,
    TOKENMODE_OCT,
    TOKENMODE_CHAR,
} TokenMode;

typedef struct Token {
    TokenKind kind;
    TokenMode mode;
    const char *start;
    const char *end;
    union {
        int64_t int_val;
        double float_val;
        const char *str_val;
        const char *name;
    };
} Token;

#endif //MOME_LEXER_H
