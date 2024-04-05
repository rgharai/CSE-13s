#include "code.h"
#include "defines.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

Code code_init(void) {
    Code c;
    for (uint64_t i = 0; i < MAX_CODE_SIZE; ++i) {
        c.bits[i] = 0;
    }
    c.top = 0;

    return c;
}

uint32_t code_size(Code *c) {
    return (c->top);
}

bool code_empty(Code *c) {
    if (c->top == 0) {
        return true;
    }
    return false;
}

bool code_full(Code *c) {
    if (c->top == ALPHABET) {
        return true;
    }
    return false;
}

bool code_set_bit(Code *c, uint32_t i) {
    if (i < ALPHABET) {
        c->bits[i / 8] = (c->bits[i / 8]) | (1 << (i % 8));
        return true;
    }
    return false;
}

bool code_clr_bit(Code *c, uint32_t i) {
    if (i < ALPHABET) {
        c->bits[i / 8] = (c->bits[i / 8]) & ~(1 << (i % 8));
        return true;
    }
    return false;
}

bool code_get_bit(Code *c, uint32_t i) {
    if (((c->bits[i / 8] >> (i % 8)) & 1) == 1) {
        return true;
    }
    return false;
}

bool code_push_bit(Code *c, uint8_t bit) {
    if (code_full(c) == false) {
        if (bit == 1) {
            code_set_bit(c, c->top);
            ++c->top;
            return true;
        }
        if (bit == 0) {
            code_clr_bit(c, c->top);
            ++c->top;
            return true;
        }
    }
    return false;
}

bool code_pop_bit(Code *c, uint8_t *bit) {
    if (code_empty(c) == false) {
        if (code_get_bit(c, c->top - 1) == true) {
            --c->top;
            *bit = 1;
            code_clr_bit(c, c->top);
            return true;
        }
        if (code_get_bit(c, c->top - 1) == false) {
            --c->top;
            *bit = 0;
            code_clr_bit(c, c->top);
            return true;
        }
    }
    return false;
}

void code_print(Code *c) {
    uint32_t cSize = code_size(c);
    for (uint32_t i = 0; i < cSize; ++i) {
        printf("%d  \n", c->bits[i]);
    }
}
