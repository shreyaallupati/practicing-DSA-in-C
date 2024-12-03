// CONVERT A MAX HEAP INTO A MIN HEAP.

#include <stdio.h>
#include <stdlib.h>

void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;

        minHeapify(arr, n, smallest);
    }
}

void buildMinHeap(int arr[], int n) {
	int i;
    for (i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);
}

void convertMaxToMinHeap(int arr[], int n) {
    int i;
	for (i = 0; i < n; i++)
        arr[i] = -arr[i];

    buildMinHeap(arr, n);

    for (i = 0; i < n; i++)
        arr[i] = -arr[i];
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    convertMaxToMinHeap(arr, n);

    printf("Min Heap: ");
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
