#include "insert.h"

#include "stats.h"

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

#define SEED 2021
#define SIZE 20

void insertion_sort(Stats *stats, uint32_t *A, uint32_t size) {
    for (uint32_t i = 1; i < size; i += 1) {
        uint32_t m = i;
        uint32_t tp = A[i];
        while (m > 0 && (cmp(stats, tp, A[m - 1]) < 0)) {
            A[m] = A[m - 1];
            move(stats, A[m]);
            m -= 1;
        }
        A[m] = tp;
    }
}
