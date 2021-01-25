//
// Created by Josh Blatt on 2021-01-04.
//

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "../include/test_lexer.h"
#include "../../include/buffer.h"
#include "../../include/lexer.h"

bool tokensMatch(Token token1, Token token2) {
    if (token1.tokenType != token2.tokenType) {
        return false;
    }
    // If they are both syntax tokens
    if (token1.tokenType == SYNTAX) {
        if (token1.tokenSyntax.syntaxType != token2.tokenSyntax.syntaxType) {
            return false;
        }
        if (token1.tokenSyntax.syntaxType == KEYWORD) {
            if (token1.tokenSyntax.keyword != token2.tokenSyntax.keyword) {
                return false;
            }
        } else if (token1.tokenSyntax.syntaxType == SYMBOL) {
            if (token1.tokenSyntax.symbol != token2.tokenSyntax.symbol) {
                return false;
            }
        } else if (token1.tokenSyntax.syntaxType == SPECIAL_SYMBOL) {
            if (token1.tokenSyntax.specialSymbol != token2.tokenSyntax.specialSymbol) {
                return false;
            }
        } else {
            return false;
        }
    } else if (token1.tokenType == VALUE) {
        // If they are both value tokens
        if (token1.tokenValue.valueType != token2.tokenValue.valueType) {
            return false;
        }
        if (token1.tokenValue.valueType == SIGNED_INT) {
            if (token1.tokenValue.signed_integer != token2.tokenValue.signed_integer) {
                return false;
            }
        } else if (token1.tokenValue.valueType == DECIMAL) {
            if (token1.tokenValue.decimal != token2.tokenValue.decimal) {
                return false;
            }
        } else if (token1.tokenValue.valueType == STR) {
            if (strcmp(token1.tokenValue.string, token2.tokenValue.string) != 0) {
                return false;
            }
        } else if (token1.tokenValue.valueType == NAME) {
            if (strcmp(token1.tokenValue.name, token2.tokenValue.name) != 0) {
                return false;
            }
        } else if (token1.tokenValue.valueType == BOOL) {
            if (token1.tokenValue.boolean != token2.tokenValue.boolean) {
                return false;
            }
        } else {
            return false;
        }
    }
    return true;
}

void test_basic_file() {
    Token **lexerTokens = lexer("/tests/src/test_lexer_contents/basic_file.txt");
    Token *correctTokens= NULL;
    Token token;
    token.tokenType = SYNTAX;
    token.tokenSyntax.syntaxType = KEYWORD;
    token.tokenSyntax.keyword = VAR;
    buf_push(correctTokens, token);
    token.tokenType = VALUE;
    token.tokenValue.valueType = NAME;
    token.tokenValue.name = "x";
    buf_push(correctTokens, token);
    token.tokenType = SYNTAX;
    token.tokenSyntax.syntaxType = SYMBOL;
    token.tokenSyntax.symbol = ASSIGN;
    buf_push(correctTokens, token);
    token.tokenType = VALUE;
    token.tokenValue.valueType = UNSIGNED_INT;
    token.tokenValue.unsigned_integer = 0;
    buf_push(correctTokens, token);
    token.tokenType = SYNTAX;
    token.tokenSyntax.syntaxType = SPECIAL_SYMBOL;
    token.tokenSyntax.specialSymbol = SEMI_COLON;
    buf_push(correctTokens, token);

    for (int i = 0; i < buf_len(correctTokens); i++) {
        assert(tokensMatch(correctTokens[i], *lexerTokens[i]));
    }
}

void test_for_loop (){
    Token **lexerTokens = lexer("/tests/src/test_lexer_contents/for_loop.txt");
    Token *correctTokens= NULL;
    Token token;

    token.tokenType = SYNTAX;
    token.tokenSyntax.syntaxType = KEYWORD;
    token.tokenSyntax.keyword = VAR;
    buf_push(correctTokens, token);
    token.tokenType = VALUE;
    token.tokenValue.valueType = NAME;
    token.tokenValue.name = "total";
    buf_push(correctTokens, token);
    token.tokenType = SYNTAX;
    token.tokenSyntax.syntaxType = SYMBOL;
    token.tokenSyntax.symbol = ASSIGN;
    buf_push(correctTokens, token);
    token.tokenType = VALUE;
    token.tokenValue.valueType = UNSIGNED_INT;
    token.tokenValue.unsigned_integer = 0;
    buf_push(correctTokens, token);
    token.tokenType = SYNTAX;
    token.tokenSyntax.syntaxType = SPECIAL_SYMBOL;
    token.tokenSyntax.specialSymbol = SEMI_COLON;
    buf_push(correctTokens, token);

    token.tokenType = SYNTAX;
    token.tokenSyntax.syntaxType = KEYWORD;
    token.tokenSyntax.keyword = FOR;
    buf_push(correctTokens, token);
    token.tokenType = SYNTAX;
    token.tokenSyntax.syntaxType = SPECIAL_SYMBOL;
    token.tokenSyntax.specialSymbol = PARENTHESIS_OPEN;
    buf_push(correctTokens, token);
    token.tokenType = SYNTAX;
    token.tokenSyntax.syntaxType = KEYWORD;
    token.tokenSyntax.keyword = VAR;
    buf_push(correctTokens, token);
    token.tokenType = VALUE;
    token.tokenValue.valueType = NAME;
    token.tokenValue.name = "i";
    buf_push(correctTokens, token);
    token.tokenType = SYNTAX;
    token.tokenSyntax.syntaxType = SYMBOL;
    token.tokenSyntax.symbol = ASSIGN;
    buf_push(correctTokens, token);
    token.tokenType = VALUE;
    token.tokenValue.valueType = UNSIGNED_INT;
    token.tokenValue.unsigned_integer = 0;
    buf_push(correctTokens, token);
    token.tokenType = SYNTAX;
    token.tokenSyntax.syntaxType = SPECIAL_SYMBOL;
    token.tokenSyntax.specialSymbol = SEMI_COLON;
    buf_push(correctTokens, token);
    token.tokenType = VALUE;
    token.tokenValue.valueType = NAME;
    token.tokenValue.name = "i";
    buf_push(correctTokens, token);
    token.tokenType = SYNTAX;
    token.tokenSyntax.syntaxType = SYMBOL;
    token.tokenSyntax.symbol = LESS;
    buf_push(correctTokens, token);
    token.tokenType = VALUE;
    token.tokenValue.valueType = UNSIGNED_INT;
    token.tokenValue.unsigned_integer = 10;
    buf_push(correctTokens, token);
    token.tokenType = SYNTAX;
    token.tokenSyntax.syntaxType = SPECIAL_SYMBOL;
    token.tokenSyntax.specialSymbol = SEMI_COLON;
    buf_push(correctTokens, token);
    token.tokenType = SYNTAX;
    token.tokenSyntax.syntaxType = SYMBOL;
    token.tokenSyntax.symbol = ADD_ASSIGN;
    buf_push(correctTokens, token);
    token.tokenType = VALUE;
    token.tokenValue.valueType = UNSIGNED_INT;
    token.tokenValue.unsigned_integer = 1;
    buf_push(correctTokens, token);
    token.tokenType = SYNTAX;
    token.tokenSyntax.syntaxType = SPECIAL_SYMBOL;
    token.tokenSyntax.specialSymbol = PARENTHESIS_CLOSE;
    buf_push(correctTokens, token);
    token.tokenType = SYNTAX;
    token.tokenSyntax.syntaxType = SPECIAL_SYMBOL;
    token.tokenSyntax.specialSymbol = CURLY_BRACKET_OPEN;
    buf_push(correctTokens, token);

    token.tokenType = VALUE;
    token.tokenValue.valueType = NAME;
    token.tokenValue.name = "total";
    buf_push(correctTokens, token);
    token.tokenType = SYNTAX;
    token.tokenSyntax.syntaxType = SYMBOL;
    token.tokenSyntax.symbol = ADD_ASSIGN;
    buf_push(correctTokens, token);
    token.tokenType = VALUE;
    token.tokenValue.valueType = NAME;
    token.tokenValue.name = "i";
    buf_push(correctTokens, token);
    token.tokenType = SYNTAX;
    token.tokenSyntax.syntaxType = SPECIAL_SYMBOL;
    token.tokenSyntax.specialSymbol = SEMI_COLON;
    buf_push(correctTokens, token);

    token.tokenType = SYNTAX;
    token.tokenSyntax.syntaxType = SPECIAL_SYMBOL;
    token.tokenSyntax.specialSymbol = CURLY_BRACKET_CLOSE;
    buf_push(correctTokens, token);
    
    for (int i = 0; i < buf_len(correctTokens); i++) {
        assert(tokensMatch(correctTokens[i], *lexerTokens[i]));
    }
}

void test_lexer() {
    test_basic_file();
}