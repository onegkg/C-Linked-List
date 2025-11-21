//
// Created by Oneg K-G on 11/8/25.
//

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

typedef struct Node node_t;

typedef struct Node {
    node_t *next;
    void *data;
} node_t;

typedef struct Tree {
    node_t *head;
    int length;
} tree_t;

tree_t *newTree(void *value);

void insert(tree_t *tree, void *value);

void insertAt(tree_t *tree, void *value, int index);

void *get(tree_t *tree, int index);

int length(tree_t *tree);

void delete(tree_t *tree, int index);

#endif //LINKEDLIST_LINKEDLIST_H