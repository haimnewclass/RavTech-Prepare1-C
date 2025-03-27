#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>  // for sleep

#define STR_SIZE 100

char* createMessage(int i) {
    char* buffer = (char*)malloc(STR_SIZE);
    if (!buffer) {
        printf("Memory allocation failed at iteration %d\n", i);
        exit(1);
    }
    snprintf(buffer, STR_SIZE, "Message number %d", i);
    return buffer;  
}

int main4() {
    int counter = 0;

    while (1) {
        char* msg = createMessage(counter);
        printf("%s\n", msg);

        
        counter++;
        Sleep(1); 
    }

    return 0;
}
