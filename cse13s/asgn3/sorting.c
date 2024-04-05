#include "heap.h"
#include "insert.h"
#include "quick.h"
#include "set.h"
#include "shell.h"
#include "stats.h"

#include <inttypes.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define OPTIONS "aeisqhn:p:r:"

#define DEFAULT_SEED       13371453
#define DEFAULT_ARRAYSIZE  100
#define DEFAULT_PRINTCOUNT 100
#define PRINT_COLS         5
typedef enum Sort {
    INSERT,
    SHELL,
    QUICK,
    HEAP,
} Sort;

void fill_rand(uint32_t *A, int size, uint64_t seed) {
    //reinitializes the random seed to that we generate the same array each time
    srandom(seed);

    //itterates through the array
    for (int i = 0; i < size; i++) {
        // 1073741823 is 30 1s in binary
        // we are bitmasking the random number to 30 bits
        A[i] = random() & 1073741823;
    }
}

void print_array(uint32_t *A, int print_count) {
    //itterates through the array
    for (int i = 0; i < print_count; i++) {
        printf("%13" PRIu32, A[i]);

        // if the current column is the size of PRINT_COLS
        // or the printing is done, then break line
        if (((i + 1) % PRINT_COLS) == 0 || i == print_count - 1) {
            printf("\n");
        }
    }
}

int main(int argc, char **argv) {
    Set enabledSorts = empty_set(); //Set of enabled sorts
    uint64_t seed = DEFAULT_SEED;
    uint32_t array_size = DEFAULT_ARRAYSIZE;
    Stats stats;
    uint32_t print_count = DEFAULT_PRINTCOUNT;

    //parses the commandline options
    int opt;
    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        case 'a':
            // Employs all sorting algorithms.
            //enabledSorts = empty_set();
            //enabledSorts = complement_set(enabledSorts);
            enabledSorts = insert_set(enabledSorts, INSERT);
            enabledSorts = insert_set(enabledSorts, SHELL);
            enabledSorts = insert_set(enabledSorts, QUICK);
            enabledSorts = insert_set(enabledSorts, HEAP);
            break;
        case 'i':
            // Enables insert Sort.
            enabledSorts = insert_set(enabledSorts, INSERT);
            break;
        case 's':
            // Enables Shell Sort.
            enabledSorts = insert_set(enabledSorts, SHELL);
            break;
        case 'q':
            // Enables Quicksort.
            enabledSorts = insert_set(enabledSorts, QUICK);
            break;
        case 'e':
            // Enables Heapsort.
            enabledSorts = insert_set(enabledSorts, HEAP);
            break;
        case 'r':
            // Set the seed for randomization.
            seed = atoi(optarg);
            break;
        case 'n':
            // Set the array size.
            array_size = atoi(optarg);
            break;
        case 'p':
            // Number of elements to print from the array.
            print_count = atoi(optarg);
            break;
        case 'h':
            //program usage
            printf("-h \t display program help and usage.\n");
            printf("-a \t enable all sorts.\n");
            printf("-e \t enable Heap Sort.\n");
            printf("-i \t enable Insertion Sort.\n");
            printf("-s \t enable Shell Sort.\n");
            printf("-q \t enable Quick Sort.\n");
            printf("-n \t specify number of array elements (default: 100).\n");
            printf("-p \t specify number of elements to print (default: 100).\n");
            printf("-r \t specify random seed (default: 13371453).\n");
        }
    }

    if (array_size <= 0) {
        fprintf(stderr, "Can't sort an array with size 0 \n");
        exit(1);
    }

    //initializes the array and stores it in the heap where it has more space
    uint32_t *rand_nums = calloc(array_size, sizeof(uint32_t));

    //make sure there is enough space for the array to fit in memory
    if (rand_nums == NULL) {
        fprintf(stderr, "error allocating space for random number array");
        exit(1);
    }

    //fixes print_count to not be more than the array size
    if (array_size < print_count) {
        print_count = array_size;
    }

    //performs the activated sort operations
    //itterate through sort types
    for (Sort s = INSERT; s < HEAP; s++) {

        //check if current sort is activated
        if (member_set(enabledSorts, s)) {

            //resets array so that it is not sorted
            fill_rand(rand_nums, array_size, seed);

            //resets the counters
            reset(&stats);

            //performs specified sort
            switch (s) {
            case INSERT:
                printf("Insert Sort\n");
                insertion_sort(&stats, rand_nums, array_size);
                break;
            case SHELL:
                printf("Shell Sort\n");
                shell_sort(&stats, rand_nums, array_size);
                break;
            case QUICK:
                printf("Quick Sort\n");
                quick_sort(&stats, rand_nums, array_size);
                break;
            case HEAP:
                printf("Heap Sort\n");
                heap_sort(&stats, rand_nums, array_size);
                break;
            }
            printf(
                "%d elements, %lu moves, %lu compares\n", array_size, stats.moves, stats.compares);

            print_array(rand_nums, print_count);
        }
    }

    free(rand_nums);

    return 0;
}
