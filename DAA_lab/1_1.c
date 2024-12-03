#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to find the second smallest and second largest elements
void findSecondSmallestAndLargest(int arr[], int n, int *secondSmallest, int *secondLargest) {
    int smallest = INT_MAX, largest = INT_MIN;
    *secondSmallest = INT_MAX;
    *secondLargest = INT_MIN;
	int i;
    for (i = 0; i < n; i++) {
        if (arr[i] < smallest) {
            *secondSmallest = smallest;
            smallest = arr[i];
        } else if (arr[i] < *secondSmallest && arr[i] != smallest) {
            *secondSmallest = arr[i];
        }

        if (arr[i] > largest) {
            *secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > *secondLargest && arr[i] != largest) {
            *secondLargest = arr[i];
        }
    }
}

int main() {
    FILE *file = fopen("input1_1.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int n;
    fscanf(file, "%d", &n);
    if (n < 2) {
        printf("Array size must be at least 2.\n");
        fclose(file);
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        fclose(file);
        return 1;
    }
	int i;
    for (i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
    }

    fclose(file);

    int secondSmallest, secondLargest;
    findSecondSmallestAndLargest(arr, n, &secondSmallest, &secondLargest);

    if (secondSmallest == INT_MAX) {
        printf("There is no second smallest element.\n");
    } else {
        printf("Second smallest element: %d\n", secondSmallest);
    }

    if (secondLargest == INT_MIN) {
        printf("There is no second largest element.\n");
    } else {
        printf("Second largest element: %d\n", secondLargest);
    }

    free(arr);
    return 0;
}

