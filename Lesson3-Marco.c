#include <stdio.h>
#define MIN_SIZE 10
#define DEBUG_
#define ARRAY_SIZE 11
#define max(a,b) ((a) > (b) ? (a) : (b))

int main() {

	int arr[ARRAY_SIZE];

	for (size_t i = 0; i < ARRAY_SIZE; i++)
	{
		int sum = max(i, ARRAY_SIZE - i - 1);
		 //((1) > (11 - i - 1) ? (1) : (11 - i - 1))
	}

	
#ifdef DEBUG
	int a = 29;
#else
	int a = MIN_SIZE;
#endif // DEBUG

	printf("a = %d\n", a);

	return 0;
}