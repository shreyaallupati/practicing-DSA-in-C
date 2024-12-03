// 4.2 quick sort
// first element as pivot

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 500

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int low, int high,  int *iterations) {

	int pivot = arr[low];
    int i = (low + 1);
	int j;
	
	 (*iterations)++;
	
    for (j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void QuickSort(int arr[], int low, int high,  int *iterations) {
    if (low < high) {
        int pi = partition(arr, low, high, iterations);
        quickSort(arr, low, pi - 1, iterations);
        quickSort(arr, pi + 1, high,iterations);
    }
}

void readData(const char *filename, int arr[], int *n) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    *n = 0;
    while (fscanf(file, "%d", &arr[*n]) != EOF && *n < MAX_ELEMENTS) {
        (*n)++;
    }

    fclose(file);
}

void writeData(const char *filename, int arr[], int n) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }
	int i;
    for (i = 0; i < n; i++) {
        fprintf(file, "%d ", arr[i]);
    }

    fclose(file);
}

void displayMenu() {
    printf("MAIN MENU (BUBBLE SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. ERROR (EXIT)\n");
}


int main() {
    int choice;
    int arr[MAX_ELEMENTS];
    int n;
    clock_t start, end;
    double time_taken;

    displayMenu();
    printf("Enter option: ");
    scanf("%d", &choice);

    const char *inputFile, *outputFile;

    switch (choice) {
        case 1:
            inputFile = "inAsce.txt";
            outputFile = "outquickAsce.txt";
            break;
        case 2:
            inputFile = "inDesc.txt";
            outputFile = "outquickDesc.txt";
            break;
        case 3:
            inputFile = "inRand.txt";
            outputFile = "outquickRand.txt";
            break;
        default:
            printf("Invalid option. Exiting...\n");
            return 1;
    }

    readData(inputFile, arr, &n);
    printf("Before Sorting: ");
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    start = clock();
	QuickSort(arr, 0, n-1);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    writeData(outputFile, arr, n);

    printf("After Sorting: ");
	
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Number of Comparisons: %ld\n", comparisonCount);
    printf("Execution Time: %lf seconds\n", time_taken);

    return 0;
}

