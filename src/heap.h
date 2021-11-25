// Implementing heap structure.
#include "darray.h"

typedef char * Value_type; 

// Implementation of free_element depend on Value_type
void free_element(Value_type);

typedef struct cell {
    int key;
    Value_type element;
} cell;

typedef struct heap {
    darray* cells;
} heap;