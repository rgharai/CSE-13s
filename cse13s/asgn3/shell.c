#include "shell.h"

#include "stats.h"

#include <inttypes.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>

uint32_t *gaps(uint32_t *r, uint32_t p) {
    uint32_t index = 0;
    uint32_t range_int = log(3 + 2 * p) / log(3);
    //uint32_t range_int = (int)range
    uint32_t *result = (uint32_t *) malloc(sizeof(uint32_t) * range_int);
    for (uint32_t i = range_int; i > 0; i -= 1) {
        result[index] = (pow(3, i) - 1) / 2;
        index += 1;
    }
    *r = range_int;
    return result;
}

void shell_sort(Stats *stats, uint32_t *A, uint32_t size) {
    uint32_t size_gaps = 0;
    uint32_t *gap_return = gaps(&size_gaps, size);

    for (uint32_t k = 0; k < size_gaps; k += 1) {
        uint32_t gap = gap_return[k];
        for (uint32_t i = gap; i < size; i += 1) {
            uint32_t j = i;
            uint32_t tp = A[i];
            while (j >= gap && tp < A[j - gap]) {
                A[j] = A[j - gap];
                move(stats, A[j]);
                j -= gap;
            }
            A[j] = tp;
        }
    }
    free(gap_return);
}
