#include "heap.h"


int parent(int index){
    return index/2;
}
int right(int index){
    return 2*index;
}
int left(int index){
    return 2*index+1;
}

void free_element(Value_type value){
    free(value);
}

cell** getting_cells(darray* tree){
    return (cell**) tree->cells;
}

void build_heap(darray* tree){
    for (int i = tree->size/2; i >= 0; i--){
        heapify(tree,i);
    }
}

void swap(darray* tree, int index1, int index2){
    cell** cells = getting_cells(tree);
    cell* temp;
    temp = cells[index1];
    cells[index1] = cells[index2];
    cells[index2] = temp;
}

darray* insert_heap(cell* value,darray* tree){
    int index = tree->size;
    cell ** cells;
    tree = insert_darr(value,tree);
    cells = getting_cells(tree);
    while (index > 0 && cells[parent(index)]->key < value->key){
        swap(tree,parent(index),index);
        index = parent(index);
    }
    return tree;
}

cell* max(darray* tree){
    cell** cells = getting_cells(tree);
    return cells[0];
}

void heapify(darray* tree, int index){
    cell** cells = getting_cells(tree);
    int l = left(index);
    int r = left(index);
    int largest = index;
    if (l<tree->size){
        if (cells[l]->key > cells[index]->key){
            largest = l;
        }
    }
    if (r<tree->size){
        if (cells[r]->key > cells[index]->key){
            largest = r;
        }
    }

    if (largest!=index){
        swap(tree,index,largest);
        heapify(tree,largest);
    }
}
