cmake_minimum_required(VERSION 3.17)
project(mome C)

set(CMAKE_C_STANDARD 11)

add_executable(mome
        src/main.c include/buffer.h src/buffer.c include/standardIncludes.h)
