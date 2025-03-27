#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_LEN 50

int main2() {
    char* name1 = (char*)malloc(MAX_LEN);
    char* name2 = (char*)malloc(MAX_LEN);
    char* fullName = (char*)malloc(2 * MAX_LEN);

    if (!name1 || !name2 || !fullName) {
        printf("Memory allocation failed.\n");
        free(name1);
        free(name2);
        free(fullName);
        return 1;
    }

    printf("Enter first name: ");
    fgets(name1, MAX_LEN, stdin);
    name1[strcspn(name1, "\n")] = 0;  // Remove newline character

    printf("Enter last name: ");
    fgets(name2, MAX_LEN, stdin);
    name2[strcspn(name2, "\n")] = 0;  // Remove newline character

    //strcpy(fullName, name1);
    strcat(fullName, name1); 
    strcat(fullName, " ");
    strcat(fullName, name2);

    printf("Full name: %s\n", fullName);

    free(name1);
    free(name2);
    free(fullName);

    return 0;
}