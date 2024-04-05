#include "graph.h"
#include "path.h"
#include "stack.h"
#include "vertices.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>





char *names[53];
bool vPrint;


#define OPTIONS "hvui:o:"
#define BLOCK   4096
bool vPrint = false;
uint32_t tp = 0;
uint32_t rd = 0;
uint32_t call = 0;
uint32_t ll = 0;

// DFS is a recursive function that finds all possible hamiltonian paths.
void DFS(Graph *G, uint32_t v, Path *curr, Path *shortest, char *cities[], FILE *outfile) {
    graph_mark_visited(G, v); // mark the vertex as visted
    uint32_t amountVertices = graph_vertices(G);
    for (uint32_t i = 0; i < (amountVertices); ++i) { // iterate through all the paths
        if ((graph_visited(G, i) == false)) {
            if (graph_has_edge(G, v, i)) {
                path_push_vertex(curr, i, G);
                call += 1;
                DFS(G, i, curr, shortest, cities, outfile);
            }
        }
        if ((path_vertices(curr)) == (amountVertices - 1)) {
            path_push_vertex(curr, 0, G);
            if (rd == 0) {
                path_copy(shortest, curr);
                ll = path_length(curr);
            }
            if (vPrint == true) {
                if (rd == 0) {
                    fprintf(stdout, "Path length: %d\n", path_length(curr));
                    path_print(curr, stdout, cities);
                } else {
                    if (path_length(curr) < ll) {
                        fprintf(stdout, "Path length: %d\n", path_length(curr));
                        path_print(curr, stdout, cities);
                        ll = path_length(curr);
                    }
                }
            }
            if (path_length(curr) < path_length(shortest)) {
                path_copy(shortest, curr);
            }
            path_pop_vertex(curr, &temp, G);
            rounds += 1;
        }
    }
    graph_mark_unvisited(G, v);
    path_pop_vertex(curr, &v, G);
}
// to amke each of the line command run
int main(int argc, char **argv) {
    int i, j, k, c;
    char buffer[BLOCK];
    char *names[53];
    int numV = 1;
    bool und = false;
    char *newFile = malloc(256);
    char *newFileOut = malloc(256);
    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0) {
            fprintf(stdout, "SYNOPSIS\n");
            fprintf(stdout, "USAGE\n");
            fprintf(stdout, "	./tsp [-u] [-v] [-h] [-i infile] [-o outfile]\n");
            fprintf(stdout, "OPTIONS\n");
            fprintf(stdout, "	-u    Use undirected graph.\n");
            fprintf(stdout, "	-v    Enable verbose printing.\n");
            fprintf(stdout, "	-h    program usage and help.\n");
            fprintf(stdout, "	-i infile   Input containing graph (default: stdin)\n");
            fprintf(stdout, "	-o outfile  Output of computed path (default: stdout)\n");
        }
        if (strcmp(argv[i], "-u") == 0) {//a pointer array which points to each argument passed to the program.
            und = true;
        }
        if (strcmp(argv[i], "-i") == 0) {// compares strings
            strcpy(newFile, argv[i + 1]);//Copies the C string pointed by source into the array pointed by destination, including the terminating null character
            freopen(newFile, "r", stdin);//
        }
        if (strcmp(argv[i], "-o") == 0) {
            strcpy(newFileOut, argv[i + 1]);
            freopen(newFileOut, "w", stdout);//associates a new filename with the given open stream and at the same time closes the old file in the stream.
        }
        if (strcmp(argv[i], "-v") == 0) {
            vPrint = true;
        }
    }
    for (int i = 0; i < (numV + 1); ++i) { // Reading input
        fgets(buffer, BLOCK, stdin);// reads a line from the specified stream and stores it into the string pointed to by str
        if (i == 0) {
            numVertices = atoi(buffer);
            if (numVertices > 26) {
                exit(1);
            }
        } else {
            names[i - 1] = strdup(buffer);
            strtok(names[i - 1], "\n");// breaks a string into series of token
        }
    }
    Graph *graph = graph_create(numV, und); // Creating graph
    Path *currentPath = path_create();
    Path *shortestPath = path_create();
    while ((c = fscanf(stdin, "%d %d %d\n", &i, &j, &k)) != EOF) {
        if (c != 3) {
            printf("Error: malformed edge.\n");
            exit(1);
            break;
        }
        graph_add_edge(graph, i, j, k);
    }

    //graph_print(graph);
    DFS(graph, 0, currentPath, shortestPath, names, stdout);
    if (vPrint == false) {
        fprintf(stdout, "Path length: %d\n", path_length(shortestPath));
        path_print(shortestPath, stdout, names);
    }
    fprintf(stdout, "Total recursive calls: %d\n", (call + 1));

    return 0;
}
