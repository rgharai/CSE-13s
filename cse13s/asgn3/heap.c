#include "heap.h"

#include "stats.h"

#include <stdbool.h>
#include <stdint.h>

uint32_t max_c(Stats *stats, uint32_t *j, uint32_t first, uint32_t last) {
    uint32_t left = 2 * first;
    uint32_t right = left + 1;
    if (right <= last && cmp(stats, j[right - 1], j[left - 1]) == 1) {
        return right;
    }
    return left;
}

void fix_heap(Stats *stats, uint32_t *j, uint32_t first, uint32_t last) {
    bool fd = false;
    uint32_t mom = first;
    uint32_t great = max_c(stats, j, mom, last);

    while ((uint32_t)(mom <= last / 2) && !fd) {
        if (cmp(stats, j[mom - 1], j[great - 1]) == -1) {
            swap(stats, j + (mom - 1), j + (great - 1));
            mom = great;
            great = max_c(stats, j, mom, last);

        } else {
            fd = true;
        }
    }
}

void build_heap(Stats *stats, uint32_t *j, uint32_t first, uint32_t last) {
    for (uint32_t mom = (uint32_t)(last / 2); mom > first - 1; mom--) {
        fix_heap(stats, j, mom, last);
    }
}

void heap_sort(Stats *stats, uint32_t j[], uint32_t len) {
    uint32_t first = 1;
    uint32_t last = len;
    build_heap(stats, j, first, last);
    for (uint32_t leaf = last; leaf > first; leaf--) {
        swap(stats, j + (first - 1), j + (leaf - 1));
        fix_heap(stats, j, first, leaf - 1);
    }
}
