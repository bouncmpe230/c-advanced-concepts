#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int size = 5;
    
    // Allocating memory using malloc
    arr = (int *)malloc(size * sizeof(int));
    // Allocating memory using calloc
    //arr = (int *)calloc(5, sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Assigning values
    for (int i = 0; i < size; i++) {
        arr[i] = i * 10;
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    
    // Freeing memory
    free(arr);
    return 0;
}