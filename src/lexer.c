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