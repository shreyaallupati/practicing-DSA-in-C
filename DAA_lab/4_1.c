// 4.1
//bubble sort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 500

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

void bubbleSort(int arr[], int n){
	int i,j;
	for (i = 0; i < n-1; i++) {
        for ( j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int choice;
    int arr[MAX_ELEMENTS];
    int n;
    long comparisons = 0;
    clock_t start, end;
    double time_taken;

    displayMenu();
    printf("Enter option: ");
    scanf("%d", &choice);

    const char *inputFile, *outputFile;

    switch (choice) {
        case 1:
            inputFile = "inAsce.txt";
            outputFile = "outbubbleAsce.txt";
            break;
        case 2:
            inputFile = "inDesc.txt";
            outputFile = "outbubbleDesc.txt";
            break;
        case 3:
            inputFile = "inRand.txt";
            outputFile = "outbubbleRand.txt";
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
    bubbleSort(arr,n);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    writeData(outputFile, arr, n);

    printf("After Sorting: ");
	
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Number of Comparisons: %ld\n", comparisons);
    printf("Execution Time: %lf seconds\n", time_taken);

    return 0;
}

