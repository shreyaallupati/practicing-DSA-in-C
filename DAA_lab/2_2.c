/*
2.2 Aim of the program: Write a function to ROTATE_RIGHT(p1, p2 ) right an array for first p2
elements by 1 position using EXCHANGE(p, q) function that swaps/exchanges the numbers p &amp;
q. Parameter p1 be the starting address of the array and p2 be the number of elements to be
rotated.

Input:
Enter an array A of size N (9): 11 22 33 44 55 66 77 88 99
Call the function ROTATE_RIGHT(A, 5)
Output:
Before ROTATE: 11 22 33 44 55 66 77 88 99
After ROTATE: 55 11 22 33 44 66 77 88 99
*/


#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "numbers.txt"

// Function to swap two numbers
void EXCHANGE(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

// Function to rotate the first p2 elements of an array to the right by 1 position
void ROTATE_RIGHT(int *p1, int p2) {
    if (p2 > 1) {
        // Move the last element of the first p2 elements to the front
        int i;
        for (i = p2 - 1; i > 0; i--) {
            EXCHANGE(&p1[i], &p1[i - 1]);
        }
    }
}

int main() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("Could not open file\n");
        return 1;
    }

    int n;
    printf("Enter the number of elements to read: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("The number of elements should be positive.\n");
        fclose(file);
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        fclose(file);
        return 1;
    }
	int i;
    for (i = 0; i < n; i++) {
        if (fscanf(file, "%d", &arr[i]) != 1) {
            printf("Error reading file or not enough elements in the file\n");
            free(arr);
            fclose(file);
            return 1;
        }
    }

    fclose(file);

    printf("The content of the array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int p2;
    printf("Enter the number of elements to rotate (p2): ");
    scanf("%d", &p2);

    if (p2 > n) {
        printf("Error: p2 should be less than or equal to the number of elements read.\n");
        free(arr);
        return 1;
    }

    ROTATE_RIGHT(arr, p2);

    printf("After ROTATE: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
