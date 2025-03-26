#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 50

int main() {
    char* name1 = (char*)malloc(MAX_LEN);
    char* name2 = (char*)malloc(MAX_LEN);
    char* fullName = (char*)malloc(2 * MAX_LEN);

    if (!name1 || !name2 || !fullName) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter first name: ");
    fgets(name1, MAX_LEN, stdin);

    printf("Enter last name: ");
    fgets(name2, MAX_LEN, stdin);

    strcat(fullName, name1);
    strcat(fullName, " ");
    strcat(fullName, name2);

    fullName = name2;

    printf("Full name: %s\n", fullName);

    free(fullName);

    return 0;
}