#include <stdio.h>
#include <stdlib.h>

int compute_sum(int* arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];   
    }
    return sum;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int* numbers = (int*)malloc(n * sizeof(int));  // ❗ כאן הבאג: המשתמש חושב שהמקום מאופס, אבל הוא לא

    if (!numbers) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    
    int sum = compute_sum(numbers, n);

    printf("The sum of all elements is: %d\n", sum);

    free(numbers);
    return 0;
}
