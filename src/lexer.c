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
    char *line = malloc(sizeof(char) * 1000);
    while(fgets(line, 1000, file) != NULL) {
        buf_push(text, line);
        line = malloc(sizeof(char) * 1000);
    }
    free(line);
    fclose(file);
    return text;
}

Token *lexer() {
    char **text = NULL;
    char *dir = createFullDirFromRoot("/tests/src/test_lexer_contents/basic_lexer.txt");
    text = readFile(dir, text);

    Token *tokens = NULL;
    char *curWord = NULL;

    for (int line = 0; line < buf_len(text); line++) {
        for (int charIndex = 0; charIndex < strlen(text[line]); charIndex++) {
            if (text[line][charIndex] == ' ') {
                //is there an unmatched quotation mark before?
                    //if so, keep reading (since string is ongoing)

                //do keyword processing of word
                //if keyword -> make token
                //else if operator -> make token
                //else if special character -> make token
                //else if name -> make name token
                //
            } else if (text[line][charIndex] == '\n') {
                //is there an unmatched quotation mark?
                    //if so, keep reading (since it is part of string)
            } else {
                strncat(curWord, &text[line][charIndex], 1); // Copy character into word
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