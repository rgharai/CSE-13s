#include "code.h"
#include "defines.h"
#include "huffman.h"
#include "io.h"
#include "node.h"
#include "pq.h"
#include "stack.h"

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdint.h>

int leaves;
uint64_t headSize;

Node *build_tree(uint64_t hist[static ALPHABET]) {
    Node *n;
    Node *left;
    Node *right;
    Node *joined = NULL;
    PriorityQueue *pq = pq_create(ALPHABET);

    // Loop thorugh alphabet
    for (int i = 0; i < ALPHABET; i++) {
        // If there is a histogram entry for a character create a node for the character and equeue
        if (hist[i] != 0) {
            n = node_create(i, hist[i]);
            enqueue(pq, n);
        }
    }

    // Dequeue the 2 nodes (left and right) and enqueue the joined node
    // The last node left is the root node
    while (pq_size(pq) > 1) {
        dequeue(pq, &left);
        dequeue(pq, &right);
        joined = node_join(left, right);
        enqueue(pq, joined);
    }

    dequeue(pq, &joined);
    pq_delete(&pq);
    return joined;
}

void build_codes(Node *root, Code table[static ALPHABET]) {
    static Code c = { 0, { 0 } };
    uint8_t bit;
    // If the root exists
    if (root) {

        // At a leaf node set the index of symbol to the code
        if (root->left == NULL && root->right == NULL) {
            table[root->symbol] = c;
        } else {
            // Recursively call with left. Left is represented by 0 and right is represetned by 1
            code_push_bit(&c, 0);
            build_codes(root->left, table);
            code_pop_bit(&c, &bit);

            code_push_bit(&c, 1);
            build_codes(root->right, table);
            code_pop_bit(&c, &bit);
        }
    }
    return;
}

void dump_tree(int outfile, Node *root) {
    if (root) {
        dump_tree(outfile, root->left);
        dump_tree(outfile, root->right);
    }
    if (!(root->left) && !(root->right)) {
        write_bytes(outfile, 0, 'L');
        write_bytes(outfile, 0, root->symbol);
    } else {
        write_bytes(outfile, 0, 'I');
    }
}

Node *rebuild_tree(uint16_t nbytes, uint8_t tree[static nbytes]) {
    Stack *s = stack_create(nbytes);
    Node *result;
    for (int i = 0; i < nbytes; ++i) {
        if (tree[i]
            == 76) { // 76 equates to an "L" which means that the character after it is a unique symbol
            Node *n = node_create(tree[i + 1], 1);
            stack_push(s, n);
        }
        if (tree[i]
            == 73) { // 73 equates to an I so we pop the right and left nodes from the stack and join them
            Node *right;
            Node *left;
            Node *joined;
            stack_pop(s, &right);
            stack_pop(s, &left);
            joined = node_join(left, right);
            stack_push(s, joined);
        }
    }
    //printf("STACK \n");
    //stack_print(s);
    stack_pop(s, &result);
    return result; // We want to return ultimate root node
}

void delete_tree(Node **root) {
    if (*root) {
        delete_tree(&(*root)->left);
        delete_tree(&(*root)->right);
        node_delete(root);
    }
    return;
}
