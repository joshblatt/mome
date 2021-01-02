//
// Created by Josh Blatt on 2021-01-01.
//

#ifndef MOME_BUFFER_H
#define MOME_BUFFER_H

#endif //MOME_BUFFER_H

#include "standardIncludes.h"

// Buffer Header
typedef struct BufferHdr {
    size_t length;
    size_t capacity;
    char buffer[0]; // Prefix of in memory data structure
} BufferHdr;

//bufferLength
//bufferCapacity
//bufferPush
//bufferFree