cmake_minimum_required(VERSION 3.17)
project(mome C)

set(CMAKE_C_STANDARD 11)

add_executable(mome
        include/buffer.h
        include/common.h
        include/lexer.h
        include/parser.h
        src/common.c
        src/main.c
        src/lexer.c
        src/parser.c
        tests/include/test_buffer.h
        tests/include/test_lexer.h
        tests/include/test_parser.h
        tests/include/unitTests.h
        tests/src/test_buffer.c
        tests/src/test_lexer.c
        tests/src/test_parser.c
        tests/src/unitTests.c)
