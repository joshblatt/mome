//
// Created by Josh Blatt on 2021-01-03.
//

#include <stdbool.h>
#include "../include/buffer.h"
#include "../include/lexer.h"

void initKeywords() {
    static bool init = false;
    if (init) {
        return;
    }
    buf_push(keywords, typedef_keyword);
    buf_push(keywords, enum_keyword);
    buf_push(keywords, struct_keyword);
    buf_push(keywords, union_keyword);
    buf_push(keywords, var_keyword);
    buf_push(keywords, const_keyword);
    buf_push(keywords, func_keyword);
    buf_push(keywords, sizeof_keyword);
    buf_push(keywords, break_keyword);
    buf_push(keywords, continue_keyword);
    buf_push(keywords, return_keyword);
    buf_push(keywords, if_keyword);
    buf_push(keywords, else_keyword);
    buf_push(keywords, while_keyword);
    buf_push(keywords, do_keyword);
    buf_push(keywords, for_keyword);
    buf_push(keywords, switch_keyword);
    buf_push(keywords, case_keyword);
    buf_push(keywords, default_keyword);
}

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

const char *token_kind_names[] = {
    [TOKEN_EOF] = "EOF",
    [TOKEN_INT] = "int",
    [TOKEN_FLOAT] = "float",
    [TOKEN_STR] = "string",
    [TOKEN_NAME] = "name",
    [TOKEN_LSHIFT] = "<<",
    [TOKEN_RSHIFT] = ">>",
    [TOKEN_EQ] = "==",
    [TOKEN_NOTEQ] = "!=",
    [TOKEN_LTEQ] = "<=",
    [TOKEN_GTEQ] = ">=",
    [TOKEN_AND] = "&&",
    [TOKEN_OR] = "||",
    [TOKEN_INC] = "++",
    [TOKEN_DEC] = "--",
    [TOKEN_COLON_ASSIGN] = ":=",
    [TOKEN_ADD_ASSIGN] = "+=",
    [TOKEN_SUB_ASSIGN] = "-=",
    [TOKEN_OR_ASSIGN] = "|=",
    [TOKEN_LSHIFT_ASSIGN] = "<<=",
    [TOKEN_RSHIFT_ASSIGN] = ">>=",
    [TOKEN_AND_ASSIGN] = "&=",
    [TOKEN_XOR_ASSIGN] = "^=",
    [TOKEN_DIV_ASSIGN] = "/=",
    [TOKEN_MOD_ASSIGN] = "%=",
};

typedef struct Token {
    TokenKind kind;
    TokenMode mode;
    const char *start;
    const char *end;
    union {
        uint64_t int_val;
        double float_val;
        const char *str_val;
        const char *name;
    };
} Token;