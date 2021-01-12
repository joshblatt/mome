//
// Created by Josh Blatt on 2021-01-03.
//

#include <assert.h>
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

Keyword isKeyword(char *word) {
    for (int i = 0; i < NUM_KEYWORDS; i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return i;
        }
    }
    return NOT_KEYWORD;
}

bool isSpecialCharacter(char c) {
    for (int i = 0; i < NUM_SPECIAL_SYMBOLS; i++) {
        if (c == specialSymbols[i]) {
            return true;
        }
    }
    return false;
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
            if (text[line][charIndex] == ' ') {
                //is there an unmatched quotation mark before?
                //if so, keep reading (since string is ongoing)
                if (unmatchedQuotation) {
                    buf_push(curWord, ' ');
                    continue;
                }
                Keyword keyword = isKeyword(curWord);
                if (keyword != NOT_KEYWORD) {
                    token = (Token *)xmalloc(sizeof(Token));
                    token->type.keyword = keyword;
                    buf_push(tokens, token);
                }


                //do keyword processing of word
                //if keyword -> make token
                //else if operator -> make token
                //else if special character -> make token
                //else if name -> make name token
                //
            } else if (text[line][charIndex] == '\n') {
                //is there an unmatched quotation mark?
                    //if so, keep reading (since it is part of string)
            } else if (isSpecialCharacter(text[line][charIndex])) {
                // does symbol come after variable?
                    //if so, create token for variable and create token for symbol
                    //if not, create token for symbol

                // if quotation mark, unmatchedQuotation = !unmatchedQuotation
            }
            else {
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