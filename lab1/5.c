#include <stdio.h>

void displayArray(int arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void deleteAtIndex(int arr[], int *size, int index) {
    if (index < 0 || index >= *size) {
        printf("Invalid index for deletion.\n");
        return;
    }

    for (int i = index; i < (*size) - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*size)--;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original ");
    displayArray(arr, size);

    deleteAtIndex(arr, &size, 0);
    printf("After deleting from the 0th position: ");
    displayArray(arr, size);

    deleteAtIndex(arr, &size, size - 1);
    printf("After deleting from the last position: ");
    displayArray(arr, size);

    int position;
    printf("Enter the position to delete: ");
    scanf("%d", &position);
    deleteAtIndex(arr, &size, position);
    printf("After deleting from position %d: ", position);
    displayArray(arr, size);

    return 0;
}