//Assignment 6

#include <stdio.h>

void insertSorted(int arr[], int n, int element) {
    int i, j;

    // Find the index where the element should be inserted
    for (i = 0; i < n; i++) {
        if (arr[i] >= element) {
            break;
        }
    }

    // Shift elements to the right to make space for the new element
    for (j = n; j > i; j--) {
        arr[j] = arr[j - 1];
    }

    // Insert the element at the determined index
    arr[i] = element;
}

int main() {
    int sortedArray[] = {1, 3, 5, 7, 9};
    int n = sizeof(sortedArray) / sizeof(sortedArray[0]);
    int elementToInsert = 4;

    insertSorted(sortedArray, n, elementToInsert);

    // Print the sorted array with the new element
    for (int i = 0; i < n + 1; i++) {
        printf("%d ", sortedArray[i]);
    }

    return 0;
}

