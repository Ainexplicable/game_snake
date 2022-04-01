//
// Created on 2022-03-31.
//

#include "LinkedList.h"

/**
 * @brief Constructs an empty list.
 */
LinkedList* create_linked_list()
{
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    if (!list)
        return NULL;
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

/**
 * Tells if the argument is the index of an existing element.
 */
_Bool is_element_index(LinkedList* list, int index)
{
    return index >= 0 && index < list->size;
}

/**
 * Tells if the argument is the index of a valid position for an
 * iterator or an add operation.
 */
_Bool is_position_index(LinkedList* list, int index)
{
    return index >= 0 && index <= list->size;
}

/**
 * @brief Inserts the specified element at the specified position in this list.
 * Shifts the element currently at that position (if any) and any
 * subsequent elements to the right (adds one to their indices).
 *
 * @param list
 * @param index index at which the specified element is to be inserted
 * @param value element to be inserted
 */
void add(LinkedList* list, int index, int value)
{
    if (!is_position_index(list, index))
        return;

    ChainNode* add = (ChainNode*)malloc(sizeof(ChainNode));
    if (!add)
        return;
    add->value = value;
    add->next = NULL;
    add->pre = NULL;

    if (list->size == 0)
    {
        list->head = add;
        list->tail = add;
    }
    else if (list->size == index)
    {
        // linkLast
        list->tail->next = add;
        add->pre = list->tail;
        list->tail = add;
    }
    else
    {
        // linkBefore
        ChainNode* right = get_node(list, index);
        ChainNode* left = right->pre;
        add->pre = left;
        add->next = right;

        right->pre = add;
        if (left)
            left->next = add;
        else
            list->head = add;
    }
    list->size++;
}

/**
 * @brief Removes the element at the specified position in this list.
 * Returns the element that was removed from the list.
 *
 * @param list
 * @param index the index of the element to be removed
 * @return the element previously at the specified position
 */
int remove1(LinkedList* list, int index)
{
    if (!is_element_index(list, index))
        return INT_MIN;

    ChainNode* remove = get_node(list, index);
    int prev_value = remove->value;
    if (remove == list->head)
        list->head = remove->next;
    else
        remove->pre->next = remove->next;

    if (remove == list->tail)
        list->tail = remove->pre;
    else
        remove->next->pre = remove->pre;
    free(remove);
    list->size--;
    return prev_value;
}

/**
 * @brief Replaces the element at the specified position in this list
 * with the specified element.
 *
 * @param list
 * @param index index of the element to replace
 * @param value element to be stored at the specified position
 * @return the element previously at the specified position
 */
int set(LinkedList* list, int index, int value)
{
    if (!is_element_index(list, index))
        return INT_MIN;
    ChainNode* p = get_node(list, index);
    int prev_value = p->value;
    p->value = value;
    return prev_value;
}

/**
 * @brief Returns the pointer at the specified position in this list.
 *
 * @param list
 * @param index index of the pointer to return
 * @return the pointer at the specified position in this list
 */
ChainNode* get_node(LinkedList* list, int index)
{
    if (!is_element_index(list, index))
        return NULL;

    ChainNode* p = NULL;
    int i = 0;
    if (index < list->size / 2)
    {
        p = list->head;
        while (i++ < index)
            p = p->next;
    }
    else
    {
        p = list->tail;
        i = list->size - 1;
        while (i-- > index)
            p = p->pre;
    }
    return p;
}

/**
 * @brief Returns the element at the specified position in this list.
 *
 * @param list
 * @param index index of the element to return
 * @return the element at the specified position in this list
 */
int get(LinkedList* list, int index)
{
    ChainNode* p = get_node(list, index);
    return p ? p->value : INT_MIN;
}

/**
 * @brief Returns the index of the first occurrence of the specified element in this list,
 * or -1 if this list does not contain the element.
 *
 * @param list
 * @param value element to search for
 * @return the index of the first occurrence of the specified element in this list,
 * or -1 if this list does not contain the element
 */
int index_of(LinkedList* list, int value)
{
    int i = 0;
    for (ChainNode* p = list->head; p; p = p->next)
    {
        if (p->value == value)
            return i;
        i++;
    }
    return -1;
}

/**
 * @brief Returns the index of the last occurrence of the specified element in this list,
 * or -1 if this list does not contain the element.
 *
 * @param list
 * @param value element to search for
 * @return the index of the last occurrence of the specified element in this list,
 * or -1 if this list does not contain the element
 */
int last_index_of(LinkedList* list, int value)
{
    int i = list->size - 1;
    for (ChainNode* p = list->tail; p; p = p->pre)
    {
        if (p->value == value)
            return i;
        i--;
    }
    return -1;
}

/**
 * @brief Removes all of the elements from this list.
 * The list will be empty after this call returns.
 *
 * @param list
 */
void clear(LinkedList* list)
{
    ChainNode* p = list->head;
    ChainNode* next;
    while (p)
    {
        next = p->next;
        free(p);
        p = next;
    }
    list->head = list->tail = NULL;
    list->size = 0;
}

/**
 * @brief Returns true if this list contains the specified element.
 *
 * @param list
 * @param value element whose presence in this list is to be tested
 * @return true if this list contains the specified element
 */
_Bool contains(LinkedList* list, int value)
{
    return index_of(list, value) != -1;
}

int front(LinkedList* list)
{
    return (list->size == 0) ? INT_MIN : list->head->value;
}

int rear(LinkedList* list)
{
    return (list->size == 0) ? INT_MIN : list->tail->value;
}

void enqueue(LinkedList* list, int value)
{
    add(list, list->size, value);
}

int dequeue(LinkedList* list)
{
    return remove1(list, 0);
}

/**
 * @brief Returns a string representation of this collection.
 * The string representation consists of a list of the collection's elements
 * in the order they are returned by its iterator, enclosed in square brackets ("[]").
 * Adjacent elements are separated by the characters ", " (comma and space).
 *
 * @param list
 */
void print_string(LinkedList* list)
{
    if (list->size == 0)
    {
        printf("[]\n");
        return;
    }
    ChainNode* p = list->head;
    printf("[%d", p->value);
    while (p = p->next)
    {
        printf(", %d", p->value);
    }
    printf("]\n");
}
