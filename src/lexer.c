//
// Created by Josh Blatt on 2021-01-03.
//

#include <assert.h>
#include <ctype.h>
#include "stdio.h"
#include <string.h>
#include <unistd.h>

#include "../include/buffer.h"
#include "../include/lexer.h"

char *createFullDirFromRoot(char *dirFromRoot) {
    int dirSize = 1000;
    char *dir = (char *)malloc(sizeof(char) * dirSize); // Directory can be max of 1000 characters
    assert(getcwd(dir, dirSize) != NULL);
    strcat(dir, dirFromRoot);
    return dir;
}

char **readFile(char *dir, char **text) {
    FILE *file;
    file = fopen(dir, "r");
    assert(file != NULL);
    // line can be 1000 characters
    char *line = (char *)xmalloc(sizeof(char) * 1000);
    while(fgets(line, 1000, file) != NULL) {
        buf_push(text, line);
        line = (char *)malloc(sizeof(char) * 1000);
    }
    free(line);
    fclose(file);
    return text;
}

typedef enum Number {
    INTEGER,
    FLOAT,
    NOT_NUMBER
} Number;

Number isNumber(char *word) {
    Number number;
    bool periodSeen = false;
    for (int i = 0; i < strlen(word); i++) {
        if (!isdigit(word[i]) && word[i] != '.') {
            return NOT_NUMBER;
        } else if (!periodSeen && word[i] == '.') {
            if (i == (strlen(word) - 1)) {
                // TODO throw error and delete this
                return NOT_NUMBER;
            } else {
                number = FLOAT;
                periodSeen = true;
            }
        } else if (periodSeen && word[i] == '.') {
            // TODO throw error and delete this
            return NOT_NUMBER;
        } // else it is a number and the loop can continue
    }
    if (!periodSeen) {
        number = INT;
    }
    return number;
}

Keyword isKeyword(char *word) {
    for (int i = 0; i < NUM_KEYWORDS; i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return i;
        }
    }
    return NOT_KEYWORD;
}

Symbol isSymbol(char *word) {
    for (int i = 0; i < NUM_SYMBOLS; i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return i;
        }
    }
    return NOT_SYMBOL;
}

SpecialSymbol isSpecialSymbol(char c) {
    for (int i = 0; i < NUM_SPECIAL_SYMBOLS; i++) {
        if (c == specialSymbols[i]) {
            return i;
        }
    }
    return NOT_SPECIAL_SYMBOL;
}

Token **lexer() {
    char **text = NULL;
    char *dir = createFullDirFromRoot("/tests/src/test_lexer_contents/basic_lexer.txt");
    text = readFile(dir, text);

    Token **tokens = NULL;
    Token *token = NULL;
    char *curWord = NULL;

    for (int line = 0; line < buf_len(text); line++) {
        for (int charIndex = 0; charIndex < strlen(text[line]); charIndex++) {
            bool unmatchedQuotation = false;
            SpecialSymbol specialSymbol = isSpecialSymbol(text[line][charIndex]);
            if (text[line][charIndex] == ' ' || text[line][charIndex] == '\n') {
                //is there an unmatched quotation mark before?
                //if so, keep reading (since string is ongoing)
                if (unmatchedQuotation) {
                    buf_push(curWord, ' ');
                    continue;
                }
                Keyword keyword = isKeyword(curWord);
                Symbol symbol = isSymbol(curWord);
                Number number = isNumber(curWord);
                token = (Token *)xmalloc(sizeof(Token));
                if (keyword != NOT_KEYWORD) {
                    token->type.keyword = keyword;
                } else if (symbol != NOT_SYMBOL) {
                    token->type.symbol = symbol;
                } else if (number != NOT_NUMBER) {
                    if (number == INTEGER) {
                        token->value.unsigned_integer = atoi(curWord);
                    } else { //float
                        token->value.decimal = atof(curWord);
                    }
                } else {
                    // if its not a keyword, symbol, or number, it must be a name
                    token->value.string = curWord;
                }
                buf_push(tokens, token);
                curWord = NULL; // reset curWord
            } else if (specialSymbol != NOT_SPECIAL_SYMBOL) {
                if (text[line][charIndex] == specialSymbols[QUOTATION] && unmatchedQuotation) {
                    token = (Token *)xmalloc(sizeof(Token));
                    token->value.string = curWord;
                    buf_push(tokens, token);
                    token = (Token *)xmalloc(sizeof(Token));
                    token->type.specialSymbol = QUOTATION;
                    buf_push(tokens, token);
                    unmatchedQuotation = false;
                } else if (text[line][charIndex] == specialSymbols[QUOTATION] && !unmatchedQuotation) {
                    token = (Token *)xmalloc(sizeof(Token));
                    token->type.specialSymbol = QUOTATION;
                    buf_push(tokens, token);
                    unmatchedQuotation = true;
                } else {
                    token = (Token *)xmalloc(sizeof(Token));
                    token->value.string = curWord;
                    buf_push(tokens, token);
                    token = (Token *)xmalloc(sizeof(Token));
                    token->type.specialSymbol = specialSymbol;
                    buf_push(tokens, token);
                }

                // if quotation mark, unmatchedQuotation = !unmatchedQuotation
            } else {
                buf_push(curWord, text[line][charIndex]); // push letter into word
                //strncat(curWord, &text[line][charIndex], 1); // Copy character into word
            }

            //
            //printf("%c", text[line][charIndex]);
        }
    }

    // Memory cleanup
    for (int i = 0; i < buf_len(text); i++) {
        free(text[i]);
    }
    buf_free(text);
    free(dir);
    return tokens;
}