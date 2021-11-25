#include "darray.h"
#include <stdio.h>
int main(){
    int arr[10] = {2,3,4,5,6,7,8,9,10,11};
    darray* darr = initialize_set(5);
    for (int i = 0; i < 10; i++){
        darr = insert(arr+i,darr);
    }
    printf("working\n");
    for (int i = 0; i < darr->size; i++){
        int value = *(( int* ) darr->cells[i]);
        printf("%d ",value);
    }
    printf("\n");
}