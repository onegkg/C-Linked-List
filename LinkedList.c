#include "LinkedList.h"

#include <stddef.h>
#include <stdlib.h>
// typedef struct Node {
//     node_t *next;
//     void *data;
// } node_t;
//
// typedef struct Tree {
//     node_t *head;
//     int length;
// } tree_t;

tree_t *newTree(void *value) {
    tree_t *tree = malloc(sizeof(tree_t));
    node_t *treeHead = malloc(sizeof(node_t));
    treeHead->next = NULL;
    treeHead->data = value;
    tree->head = treeHead;
    tree->length = 1;
    return tree;
}

void insert(tree_t *tree, void *value) {
    node_t *node = malloc(sizeof(node_t));
    node->data = value;
    node->next = tree->head;
    tree->length++;
    tree->head = node;
}

void insertAt(tree_t *tree, void *value, int index) {
    if (tree == NULL) {
        return;
    }
    node_t *node = malloc(sizeof(node_t));
    node->data = value;
    node_t *curr = tree->head->next;
    node_t *prev = tree->head;
    int currIdx = 0;
    while (curr != NULL) {
        if (currIdx == index) {
            prev->next = node;
            node->next = curr;
        }
        currIdx++;
    }
}

void *get(tree_t *tree, int index) {
    return NULL;
}

int length(tree_t *tree) {
    return 0;
}

void delete(tree_t *tree, int index) {
}
