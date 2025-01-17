#include "path.h"

#include "graph.h"
#include "stack.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct Path {
    Stack *vertices; // The vertices comprising the path .
    uint32_t length; // The total length of the path .
};

Path *path_create(void) {
    Path *p = (Path *) malloc(sizeof(Path));
    if (p) {
        p->vertices = stack_create(26);
        p->length = 0;
    }
    return p;
}

void path_delete(Path **p) {
    free(((*p)->vertices));
    free(*p);
    *p = NULL;
    return;
}

bool path_push_vertex(Path *p, uint32_t v, Graph *G) {
    uint32_t stackPeek;
    stack_peek((p->vertices), &stackPeek);
    if ((graph_edge_weight(G, stackPeek, v))
        > 0) { // If there is a weight/connection from wehre we were to the new vertex, then add to stack and length.
        p->length += graph_edge_weight(G, stackPeek, v);
        stack_push((p->vertices), v);
        return true;
    } else {
        return false;
    }
}

bool path_pop_vertex(Path *p, uint32_t *v, Graph *G) {
    uint32_t stackPeek;
    if (stack_empty(p->vertices) == true) {
        return false;
    }
    stack_pop(p->vertices, v);
    if (stack_empty(p->vertices) == true) {
        p->length -= graph_edge_weight(G, 0, *v);
        return true;
    }
    stack_peek((p->vertices), &stackPeek);
    if ((graph_edge_weight(G, stackPeek, *v)) > 0) {
        p->length -= graph_edge_weight(G, stackPeek, *v);
        return true;
    }

    return false;
}

uint32_t path_vertices(Path *p) {
    return (stack_size(p->vertices));
}

uint32_t path_length(Path *p) {
    return (p->length);
}

void path_copy(Path *dst, Path *src) {
    dst->length = src->length;
    stack_copy((dst->vertices), (src->vertices));
    return;
}

void path_print(Path *p, FILE *outfile, char *cities[]) {
    stack_print(p->vertices, outfile, cities);
    return;
}
