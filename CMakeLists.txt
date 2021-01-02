cmake_minimum_required(VERSION 3.17)
project(mome C)

set(CMAKE_C_STANDARD 11)

add_executable(mome
        src/main.c
        include/buffer.h
        include/standardIncludes.h
        tests/src/test_buffer.c
        tests/src/unitTests.c
        tests/include/unitTests.h
        tests/include/test_buffer.h)
