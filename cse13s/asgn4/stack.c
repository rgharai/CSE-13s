#include "stack.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct Stack {
    uint32_t top; // Index of the next empty slot .
    uint32_t capacity; // Number of items that can be pushed .
    uint32_t *items; // Array of items , each with type uint32_t .
};
//creating the stack
Stack *stack_create(uint32_t capacity) {
    Stack *s = (Stack *) malloc(sizeof(Stack));
    if (s) {
        s->top = 0;
        s->capacity = capacity;
        s->items = (uint32_t *) calloc(capacity, sizeof(uint32_t));
        if (!s->items) {
            free(s);
            s = NULL;
        }
    }

    return s;
}
//The destructor function for a stack.
void stack_delete(Stack **s) {
    if (*s && (*s)->items) {
        free((*s)->items);
        free(*s);
        *s = NULL;
    }
    return;
}
// to see how many items in stack
uint32_t stack_size(Stack *s) {
    return (s->top);
}
// to check if stack is empty
bool stack_empty(Stack *s) {
    if (s->top == 0) {
        return true;
    } else {
        return false;
    }
}
// to check if stack is full
bool stack_full(Stack *s) {
    if (s->top == s->capacity) {
        return true;
    } else {
        return false;
    }
}

// We cannot push if stack is full. place itme in array and icrement top
bool stack_push(Stack *s, uint32_t x) {
    if (s->top == (s->capacity)) {
        return false;
    }
    s->items[s->top] = x;
    s->top += 1;
    return true;
}

bool stack_peek(Stack *s, uint32_t *x) {
    if (stack_empty(s) == true) {
        *x = 0;
        return false;
    }
    s->top -= 1;
    *x = s->items[s->top];
    s->top += 1;
    return true;
}

// Decrement top and place item in specified location
bool stack_pop(Stack *s, uint32_t *x) {
    if (s->top == 0) {
        return false;
    }
    s->top -= 1;
    *x = s->items[s->top];
    return true;
}

//Copying capacity and top first. Then we set all items in destination array to whatever is in source array
void stack_copy(Stack *dst, Stack *src) {
    dst->capacity = src->capacity;
    dst->top = src->top;
    for (uint64_t i = 0; i < (src->capacity); ++i) {
        dst->items[i] = src->items[i];
    }
}

// print origin first and then all others
void stack_print(Stack *s, FILE *outfile, char *cities[]) {
    fprintf(outfile, "%s -> ", cities[0]);
    for (uint32_t i = 0; i < (s->top); i += 1) {
        fprintf(outfile, "%s", cities[s->items[i]]);
        if (i + 1 != s->top) {
            fprintf(outfile, " -> ");
        }
    }
    fprintf(outfile, "\n");
}
