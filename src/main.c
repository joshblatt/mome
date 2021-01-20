//
// Created by Josh Blatt on 2021-01-01.
//

#include <stdio.h>
#include "../include/lexer.h"
#include "../tests/include/unitTests.h"


int main(int argc, const char *argv[]) {
    runUnitTests();
    lexer("/tests/src/test_lexer_contents/basic_file.txt");
    return 0;
}
