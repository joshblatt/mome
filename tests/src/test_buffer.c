//
// Created by Josh Blatt on 2021-01-02.
//
#include "../../include/buffer.h"

void test_bufferLength() {
    int *buf = NULL;
    assert(buf_len(buf) == 0);
    for (int i = 0; i < 10; i++) {
        buf_push(buf, i);
    }
//    for (int i = 0; i < 10; i++) {
//        printf("%d ", buf[i]);
//    }
    assert(buf_len(buf) == 10);
    buf_free(buf);
    printf("%d\n", buf_len(buf));
    for (int i = 0; i < 10; i++) {
        printf("%d ", buf[i]);
    }
    //assert(buf_len(buf) == 0);
}

void test_bufferCapacity() {

}

void test_bufferPush() {

}
void test_bufferFree() {

}
void test_buffer() {
    test_bufferLength();
}