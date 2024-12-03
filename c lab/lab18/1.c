//program 6

// C program for the above approach
#include <stdio.h>
#include <stdlib.h>

// Function to find the largest element
// using dynamic memory allocation
void findLargest(int* arr, int N)
{
	int i;
	for (i = 1; i < N; i++) 
    {

		if (*arr < *(arr + i)) 
        {
			*arr = *(arr + i);
		}
	}
	printf("%d ", *arr);
}

int main()
{
	int i, N = 4;

	int* arr;
	arr = (int*)calloc(N, sizeof(int));

	// Condition for no memory
	// allocation
	if (arr == NULL) {
		printf("No memory allocated");
		exit(0);
	}

	// Store the elements
	*(arr + 0) = 14;
	*(arr + 1) = 12;
	*(arr + 2) = 19;
	*(arr + 3) = 20;

	// Function Call
	findLargest(arr, N);
	return 0;
}
