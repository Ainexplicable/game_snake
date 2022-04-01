//
// Created on 2022-03-31.
//

#pragma once
#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ChainNode
{
    struct ChainNode* next, * pre;
    int value;
} ChainNode;

typedef struct LinkedList
{
    struct ChainNode* head, * tail;
    int size;
} LinkedList;

LinkedList* create_linked_list();

ChainNode* get_node(LinkedList* list, int index);

_Bool is_element_index(LinkedList* list, int index);

_Bool is_position_index(LinkedList* list, int index);

void add(LinkedList* list, int index, int value);

int remove1(LinkedList* list, int index);

int set(LinkedList* list, int index, int value);

int get(LinkedList* list, int index);

int index_of(LinkedList* list, int value);

int last_index_of(LinkedList* list, int value);

void clear(LinkedList* list);

_Bool contains(LinkedList* list, int value);

int front(LinkedList* list);

int rear(LinkedList* list);

void enqueue(LinkedList* list, int value);

int dequeue(LinkedList* list);

#endif // _LINKED_LIST_H
