// Implementing heap structure.
#ifndef HEAP_HEADER
#define HEAP_HEADER
#include "darray.h"

typedef char * Value_type; 

// Implementation of free_element depend on Value_type
void free_element(Value_type);

typedef struct cell {
    int key;
    Value_type element;
} cell;

int parent(int index);
int right(int index);
int left(int index);

void heapify(darray* tree, int index);
void size(darray* tree);

#endif