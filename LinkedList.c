#include "LinkedList.h"

#include <stddef.h>
#include <stdlib.h>

/*!
 * @brief Creates a new linked list with value as the head
 * @param value A pointer to heap allocated data to be stored at the head of the list
 * @return A new linked list with value as the head or NULL if it was unable to create the list
 */
linked_list_t *newLinkedList(void *value) {
    linked_list_t *list = malloc(sizeof(linked_list_t));
    if (!list) {
        return NULL;
    }
    node_t *listHead = malloc(sizeof(node_t));
    if (!listHead) {
        free(list);
        return NULL;
    }
    listHead->next = NULL;
    listHead->data = value;
    list->head = listHead;
    list->length = 1;
    return list;
}

/*!
 * @brief Inserts an element at the head of the provided list
 * @param list the list to add the value to
 * @param value a pointer to heap allocated data to be added to the list
 * @return 0 if successful; 1 if allocation failed
 */
int insert(linked_list_t *list, void *value) {
    node_t *node = malloc(sizeof(node_t));
    if (!node) {
        return 1;
    }
    node->data = value;
    node->next = list->head;
    list->length++;
    list->head = node;
    return 0;
}

/*!
 * @brief Inserts an element at the provided index. If index is out of bounds, performs no operations
 * @param list the list to insert in
 * @param value a pointer to heap allocated data to be added to the list
 * @param index the index at which to insert the data
 * @return 0 if successfully inserted; 1 if allocation failed, 2 for invalid index, 3 if list is NULL
 */
int insertAt(linked_list_t *list, void *value, int index) {
    if (list == NULL) {
        return 3;
    }
    if (index < 0 || index > list->length) {
        return 2;
    }
    node_t *toInsert = malloc(sizeof(node_t));
    // allocation fails
    if (!toInsert) {
        return 1;
    }
    toInsert->data = value;
    node_t *curr = list->head;
    node_t *prev = NULL;
    int currIdx = 0;
    // Inserting as last element
    if (index == list->length) {
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = toInsert;
        list->length++;
        return 0;
    }
    while (curr != NULL) {
        if (currIdx == index) {
            // if inserting at index 0
            if (prev == NULL) {
                toInsert->next = list->head;
                list->head = toInsert;
                list->length++;
                return 0;
            }
            // inserting at any other index
            prev->next = toInsert;
            toInsert->next = curr;
            list->length++;
            return 0;
        }
        // iterate
        currIdx++;
        prev = curr;
        curr = curr->next;
    }
    // index out of bounds
    free(toInsert);
    return 2;
}

/*!
 * @brief Returns the element at the provided index
 * @param list the list to get the element from
 * @param index the index of the desired element
 * @return the element at the provided index, NULL if it could not be found;
 */
void *get(linked_list_t *list, int index) {
    if (list == NULL) {
        return NULL;
    }
    if (index < 0 || index >= list->length) {
        return NULL;
    }
    int currIdx = 0;
    const node_t *curr = list->head;
    while (curr != NULL) {
        if (currIdx == index) {
            return curr->data;
        }
        curr = curr->next;
        currIdx++;
    }
    return NULL;
}

/*!
 * @brief returns the length of the list
 * @param list the list to get the length of
 * @return -1 if list is NULL, otherwise the length of the list
 */
int length(linked_list_t *list) {
    if (list == NULL) {
        return -1;
    }
    return list->length;
}

/*!
 * @brief Deletes the element at the specified index in the list
 * @param list The list to delete from
 * @param index The index to delete at
 * @return 0 if successfully deleted, 2 for invalid index, 3 if list is NULL
 */
int delete(linked_list_t *list, int index) {
    if (list == NULL) {
        return 3;
    }
    if (index < 0 || index >= list->length) {
        return 2;
    }
    if (index == 0) {
        node_t* toDelete = list->head;
        list->head = toDelete->next;
        list->length--;
        free(toDelete->data);
        free(toDelete);
        return 0;
    }
    node_t *toDelete = list->head->next;
    node_t *prev = list->head;
    int currIdx = 1;
    while (toDelete != NULL) {
        if (currIdx == index) {
            prev->next = toDelete->next;
            list->length--;
            free(toDelete->data);
            free(toDelete);
            return 0;
        }
        currIdx++;
        toDelete = toDelete->next;
        prev = prev->next;
    }
    return 2;
}
