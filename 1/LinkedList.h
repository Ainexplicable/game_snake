#pragma once
#include <limits.h>
#include <stdlib.h>

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
int remove_from_list(LinkedList* list, int index);
int set(LinkedList* list, int index, int value);
int get(LinkedList* list, int index);
int index_of(LinkedList* list, int value);
int last_index_of(LinkedList* list, int value);
void clear(LinkedList* list);
_Bool contains(LinkedList* list, int value);
void print_string(LinkedList* list);
int front(LinkedList* list);
int rear(LinkedList* list);
void enqueue(LinkedList* list, int value);
int dequeue(LinkedList* list);
