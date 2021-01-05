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
    for (int i = 0; i < buf_len(text); i++) {
        printf("%s", text[i]);
    }
    Token *token = NULL;

    for (int i = 0; i < buf_len(text); i++) {
        free(text[i]);
    }
    buf_free(text);
    free(dir);
    return token;
}