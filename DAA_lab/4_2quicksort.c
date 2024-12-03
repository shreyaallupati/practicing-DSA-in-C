#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int arr[], int lb, int ub, int *iterations) {
    if (lb < ub) {
        int pivotIndex = partition(arr, lb, ub, iterations);
        quickSort(arr, lb, pivotIndex - 1, iterations);
        quickSort(arr, pivotIndex + 1, ub, iterations);
    }
}

int partition(int arr[], int lb, int ub, int *iterations) {
    int pivot = arr[lb];
    int i = lb + 1;
    int j;

    (*iterations)++;  

    for (j = lb + 1; j <= ub; j++) {
        if (arr[j] < pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[lb], &arr[i - 1]);

    return i - 1;
}

int readNumbersFromFile(const char *fileName, int **numbers) {
    FILE *file;
    int count = 0;
    int *tempNumbers = NULL;

    file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error opening %s file!\n", fileName);
        return -1;
    }

    while (fscanf(file, "%*d") != EOF) {
        count++;
    }

    tempNumbers = (int *)malloc(count * sizeof(int));
    if (tempNumbers == NULL) {
        printf("Memory allocation failed!\n");
        fclose(file);
        return -1;
    }

    rewind(file);

    int i;
    for (i = 0; i < count; i++) {
        fscanf(file, "%d", &tempNumbers[i]);
    }

    fclose(file);
    *numbers = tempNumbers;
    return count;
}

void writeNumbersToFile(const char *fileName, int numbers[], int count) {
    FILE *file;

    file = fopen(fileName, "w");
    if (file == NULL) {
        printf("Error opening %s file for writing!\n", fileName);
        return;
    }
	int i;
    for (i = 0; i < count; i++) {
        fprintf(file, "%d\n", numbers[i]);
    }

    fclose(file);
}

int main() {
    int *numbers = NULL;
    int count = 0;
    int iterations = 0;
    int choice;
    char fileName[20];

    while (1) {
        printf("\nMenu:\n");
        printf("1. Sort numbers.txt\n");
        printf("2. Sort file1.txt\n");
        printf("3. Sort file2.txt\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                strcpy(fileName, "numbers.txt");
                break;
            case 2:
                strcpy(fileName, "file1.txt");
                break;
            case 3:
                strcpy(fileName, "file2.txt");
                break;
            case 4:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Please select a valid option.\n");
                continue;
        }

        count = readNumbersFromFile(fileName, &numbers);
        if (count == -1) {
            printf("Error reading numbers from file.\n");
            continue;
        }


        iterations = 0; 
        quickSort(numbers, 0, count - 1, &iterations);

        
        writeNumbersToFile("1stpivot.txt", numbers, count);

        printf("Numbers from %s have been sorted using Quick Sort.\n", fileName);
        printf("Sorted numbers have been written to 1stpivot.txt.\n");
        printf("Number of iterations: %d\n", iterations);

        free(numbers);
        numbers = NULL;
    }

    return 0;
}
