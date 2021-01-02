//
// Created by Josh Blatt on 2021-01-02.
//
#include "../../include/buffer.h"

void test_buf_len() {
    // Test that length is correct for int
    int *buf = NULL;
    assert(buf_len(buf) == 0);
    for (int i = 0; i < 10; i++) {
        buf_push(buf, i);
    }
    assert(buf_len(buf) == 10);
    buf_free(buf);
    assert(buf_len(buf) == 0);

    // Test that length is correct for strings
    char *string = NULL;
    assert(buf_len(string) == 0);
    for (int i = 0; i < 64; i++) {
        buf_push(string, 'a');
    }
    assert(buf_len(string) == 64);
    buf_free(string);
    assert(buf_len(string) == 0);

    // Test that length is correct for size_t (which is much larger than an int
    size_t *bigBuf = NULL;
    assert(buf_len(bigBuf) == 0);
    for (int i = 0; i < 17; i++) {
        buf_push(bigBuf, i);
    }
    assert(buf_len(bigBuf) == 17);
    buf_free(bigBuf);
    assert(buf_len(bigBuf) == 0);
}

void test_buf_cap() {
    // Capacity should start at 0
    // Once a single element is pushed in, will increase to 16
    // Once current capacity is exceeded (and is less than absolute max size), capacity will double and then add 1
    int *buf = NULL;
    assert(buf_cap(buf) == 0);
    buf_push(buf, 0);
    assert(buf_cap(buf) == 16);
    for (int i = 1; i < 16; i++) {
        buf_push(buf, i);
    }
    assert(buf_cap(buf) == 16);
    buf_push(buf, 16);
    assert(buf_cap(buf) == 33);
    for (int i = 17; i < 33; i++) {
        buf_push(buf, i);
    }
    assert(buf_cap(buf) == 33);
    buf_push(buf, 33);
    assert(buf_cap(buf) == 67);

    buf_free(buf);
}

void test_buf_end() {
    // Points to the byte after the last data byte
    int *buf = NULL;
    assert(buf_end(buf) == 0);
    for (int i = 1; i < 18; i++) {
        buf_push(buf, i);
        assert(buf + i == buf_end(buf));
    }
    buf_free(buf);
    assert(buf_end(buf) == 0);
}

void test_buf_sizeof() {
    int *buf = NULL;
    assert(buf_sizeof(buf) == 0);
    int size = 17;
    for (int i = 0; i < size; i++) {
        buf_push(buf, i);
    }
    assert(buf_sizeof(buf) == size * sizeof(int));
    buf_free(buf);
    assert(buf_sizeof(buf) == 0);

    char *string = NULL;
    assert(buf_sizeof(string) == 0);
    int lettersInAlphabet = 26;
    for (char c = 'a'; c < 'a' + lettersInAlphabet; c++) {
        buf_push(string, c);
    }
    assert(buf_sizeof(string) == lettersInAlphabet * sizeof(char));
    buf_free(string);
    assert(buf_sizeof(string) == 0);
}

void test_buf_push() {
    int *buf = NULL;
    for (int i = 0; i < 17; i++) {
        buf_push(buf, i);
        assert(buf[i] == i);
    }
    buf_free(buf);

    char *string = NULL;
    for (char i = 'a'; i <= 'z'; i++) {
        buf_push(string, i);
    }
    char c = 'a';
    for (int i = 0; i < 26; i++) {
        assert(string[i] == c);
        c++;
    }
    buf_free(string);
}

void test_buf_free() {
    int *buf = NULL;
    for (int i = 0; i < 17; i++) {
        buf_push(buf, i);
    }
    buf_free(buf);
    assert(buf_len(buf) == 0);
    assert(buf_cap(buf) == 0);
    assert(buf_end(buf) == 0);
    assert(buf_sizeof(buf) == 0);
}

void test_buf_fit() {
    // Sets buf to a specific size
    int *buf = NULL;
    assert(buf_len(buf) == 0);
    assert(buf_cap(buf) == 0);
    buf_fit(buf, 4);
    // The minimum size of an initialized stretchy buffer is 16, so if something less than
    // that is passed, it will set the capacity to 16 (length remains 0)
    assert(buf_len(buf) == 0);
    assert(buf_cap(buf) == 16);

    // Will take the max of the number passed in and the capacity * 2 + 1 (which in this case will be the latter)
    buf_fit(buf, 32);
    assert(buf_len(buf) == 0);
    assert(buf_cap(buf) == 33);

    buf_free(buf);
    assert(buf_len(buf) == 0);
    assert(buf_cap(buf) == 0);

    char *string = NULL;
    buf_push(string, 'a');
    assert(buf_len(string) == 1);
    assert(buf_cap(string) == 16);

    // Should do nothing since capacity is 16 and it will take the larger of the 2
    buf_fit(string, 4);
    assert(buf_len(string) == 1);
    assert(buf_cap(string) == 16);

    //Should set the capacity to 34 since it is larger than the current capacity (16) * 2 + 1
    buf_fit(string, 34);
    assert(buf_len(string) == 1);
    assert(buf_cap(string) == 34);

    buf_free(string);
    assert(buf_len(string) == 0);
    assert(buf_cap(string) == 0);
}

void test_buffer() {
    test_buf_len();
    test_buf_cap();
    test_buf_end();
    test_buf_sizeof();
    test_buf_push();
    test_buf_free();
    test_buf_fit();
}