#include <stdlib.h>
#include "darray.h"

darray* initialize_set (int size){
    darray* new_array = malloc(sizeof(darray));
    new_array->cells = (void**) malloc(sizeof(void*)*size);
    new_array->capacity = size;
    new_array->size = 0;
    return new_array;
}

void tidy(darray* array){
    free(array->cells);
    free(array);
}

int size(darray* array){
    return array->size;
}

darray* insert(void* value, darray* array){
    darray* new_array;
    if (array->size >= array->capacity){
        int size = array->size;
        void** cells = array->cells;
        new_array = initialize_set(array->capacity*2);
        for (int i = 0; i < size; i++){
            (void) insert(cells[i],new_array);
        }
        tidy(array);
        array = new_array;
    }
    array->cells[array->size] = value;
    array->size++;
    return array;
}