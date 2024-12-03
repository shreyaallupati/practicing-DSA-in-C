#include <stdio.h>

void bubbleSort(int arr[], int n) {
    // Base case: If only one element remains, return
    if (n == 1)
        return;

    // Perform a single pass through the array
    int i;
    for (i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            // Swap elements if they are out of order
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }

    // Recur for the remaining (n-1) elements
    bubbleSort(arr, n - 1);
}

int main() {
    int n;
	int i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

