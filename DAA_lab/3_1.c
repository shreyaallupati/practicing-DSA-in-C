/* 
3.1 Aim of the program: Write a menu driven program to sort list of array elements using Merge
Sort technique and calculate the execution time only to sort the elements. Count the number of
comparisons.
Note#
1) To calculate execution time, assume that single program is under execution in the CPU.
2) Number of elements in each input file should vary from 300 to 500 entries.
3) For ascending order: Read data from a file “inAsce.dat” having content 10 20 30 40…..,
Store the result in “outMergeAsce.dat”.
4) For descending order: Read data from a file “inDesc.dat” having content 90 80 70 60….,
Store the result in “outMergeDesc.dat”.
5) For random data: Read data from a file “inRand.dat” having content 55 66 33 11 44 …,
Store the result in “outMergeRand.dat”

Sample Input from file:
MAIN MENU (MERGE SORT)
1. Ascending Data
2. Descending Data
3. Random Data
4. ERROR (EXIT)

Output:
Enter option: 1
Before Sorting: Content of the input file
After Sorting: Content of the output file
Number of Comparisons: Actual
Execution Time: lapse time in nanosecond

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 500

void merge(int arr[], int l, int m, int r, long *comparisons) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        (*comparisons)++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(int arr[], int l, int r, long *comparisons) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m, comparisons);
        mergeSort(arr, m + 1, r, comparisons);

        merge(arr, l, m, r, comparisons);
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
    printf("MAIN MENU (MERGE SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. ERROR (EXIT)\n");
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
            outputFile = "outMergeAsce.txt";
            break;
        case 2:
            inputFile = "inDesc.txt";
            outputFile = "outMergeDesc.txt";
            break;
        case 3:
            inputFile = "inRand.txt";
            outputFile = "outMergeRand.txt";
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
    mergeSort(arr, 0, n - 1, &comparisons);
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



