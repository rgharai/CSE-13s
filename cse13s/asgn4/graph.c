#include "graph.h"

#include "vertices.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct Graph {
    uint32_t vertices; // Number of vertices .
    bool undirected; //undirected graph
    bool visited[26]; // where have we gone??
    uint32_t matrix[26][26]; // Adjacency matrix .
};

#define START_VERTEX 0 // Starting ( origin ) vertex .

#define VERTICES 26 // Maximum vertices in graph .

//create a new graph with n vertices labeled 0..n-1 and no edges
Graph *graph_create(uint32_t vertices, bool undirected) {
    Graph *g = (Graph *) malloc(sizeof(Graph));
    if (g) {
        g->vertices = vertices;
        g->undirected = undirected;
        for (uint32_t i = 0; i < 26; ++i) {
            g->visited[i] = false;
            for (uint32_t j = 0; j < vertices; ++j) {
                g->matrix[i][j] = 0;
            }
        }
    }
    return g;
}

//free all space used by graph
void graph_delete(Graph **G) {
    free(*G);
    *G = NULL;
    return;
}

//return the number of vertices
uint32_t graph_vertices(Graph *G) {
    return G->vertices;
}

//add edge
bool graph_add_edge(Graph *G, uint32_t i, uint32_t j, uint32_t k) {
    if (i > (G->vertices) || j > (G->vertices)) { // checking if its within bounds
        return false;
    }
    if (i < 0 || j < 0) {
        return false;
    }
    if ((G->undirected) == true) {
        G->matrix[i][j] = k;
        G->matrix[j][i] = k;
        return true;
    }
    G->matrix[i][j] = k;
    return true;
}

bool graph_has_edge(Graph *G, uint32_t i, uint32_t j) {
    if (i > (G->vertices) || j > (G->vertices)) { // checking if it within bounds
        return false;
    }
    if (i < 0 || j < 0) {
        return false;
    }
    if ((G->matrix[i][j]) > 0) { //  Must be greater than 0 to count as an edge
        return true;
    }
    return false;
}
// return the weight of the edge
uint32_t graph_edge_weight(Graph *G, uint32_t i, uint32_t j) {
    if (i > (G->vertices) || j > (G->vertices)) { // checking if it within bounds
        return false;
    }
    if (i < 0 || j < 0) {
        return false;
    }
    return (G->matrix[i][j]);
}

bool graph_visited(Graph *G, uint32_t v) {
    return (G->visited[v]);
}
// true cause its visited
void graph_mark_visited(Graph *G, uint32_t v) {
    G->visited[v] = true;
    return;
}
// false cause it the opposite of visited
void graph_mark_unvisited(Graph *G, uint32_t v) {
    G->visited[v] = false;
    return;
}

//A debug function you will want to write to make sure your graph ADT works as expected.
void graph_print(Graph *G) {
    for (uint32_t i = 0; i < (G->vertices); ++i) {
        printf("\n");

        for (uint32_t j = 0; j < (G->vertices); ++j) {
            printf("%d	", G->matrix[i][j]);
        }
    }
    printf("\n");
    return;
}
