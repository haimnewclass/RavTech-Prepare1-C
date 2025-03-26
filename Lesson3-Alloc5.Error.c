#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 4

int main() {
    int* arr = (int*)malloc(INITIAL_SIZE * sizeof(int));
    if (!arr) {
        printf("Initial allocation failed.\n");
        return 1;
    }

    int logicalSize = 0;
    int capacity = INITIAL_SIZE;

    while (1) {
        
        arr[logicalSize] = logicalSize * 10;
        logicalSize++;

        if (logicalSize >= capacity) {
            
            capacity *= 2;
            
        }

        printf("Inserted %d (logical size: %d, capacity: %d)\n", arr[logicalSize - 1], logicalSize, capacity);

        
        if (logicalSize % 100000 == 0) {
            printf("Sleeping for a second...\n");
            sleep(1);
        }
    }

    free(arr);
    return 0;
}
