cmake_minimum_required(VERSION 3.17)
project(mome C)

set(CMAKE_C_STANDARD 11)

add_executable(mome
        include/buffer.h
        include/common.h
        include/lexer.h
        src/common.c
        src/main.c
        src/lexer.c
        tests/include/unitTests.h
        tests/include/test_buffer.h
        tests/src/test_buffer.c
        tests/src/unitTests.c
        )
