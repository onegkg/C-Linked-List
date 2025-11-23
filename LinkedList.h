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

typedef struct LinkedList {
    node_t *head;
    int length;
} linked_list_t;

linked_list_t *newLinkedList(void *value);

int insert(linked_list_t *list, void *value);

int insertAt(linked_list_t *list, void *value, int index);

void *get(linked_list_t *list, int index);

int length(linked_list_t *list);

int delete(linked_list_t *list, int index);

#endif //LINKEDLIST_LINKEDLIST_H