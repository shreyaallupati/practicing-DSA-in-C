#include <stdio.h>

#define MAX_SIZE 100

void computePrefixSum(int arr[], int prefixSum[], int size) {
    prefixSum[0] = arr[0];
    int i;
    for (i = 1; i < size; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }
}

int main() {
    int arr[MAX_SIZE], prefixSum[MAX_SIZE];
    int size;
	int i;
    // Read the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Input validation
    if (size <= 0 || size > MAX_SIZE) {
        printf("Invalid size.\n");
        return 1;
    }

    // Read the array elements
    printf("Enter %d elements:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Compute prefix sum
    computePrefixSum(arr, prefixSum, size);

    // Print the prefix sum array
    printf("Prefix Sum Array:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", prefixSum[i]);
    }
    printf("\n");

    return 0;
}

