//
// Created by Josh Blatt on 2021-01-01.
//

#ifndef MOME_COMMON_H
#define MOME_COMMON_H

#include <stddef.h>
#define MAX(x, y) ((x) >= (y) ? (x) : (y))

void *xcalloc(size_t num_elems, size_t elem_size);
void *xrealloc(void *ptr, size_t num_bytes);
void *xmalloc(size_t num_bytes);

#endif //MOME_COMMON_H

