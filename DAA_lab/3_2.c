/*
3.2 Aim of the program: Write a menu driven program to sort a list of elements in ascending order using BINARY SEARCH technique. Each choice for the input data has its own disc file.  A separate output file can be used for sorted elements. After sorting display the content of the output file along with number of comparisons. Based on the partitioning position for each recursive call, conclude the input scenario is either best-case partitioning or worst-case partitioning. 
Note# 
?The worst-case behavior for quicksort occurs when the partitioning routine produces one subproblem with n-1 elements and one with 0 elements. The best-case behaviour occurred in most even possible split, PARTITION produces two subproblems, each of size no more than n/2.
?Number of elements in each input file should vary from 300 to 500 entries. 
?For ascending order: Read data from a file “inAsce.dat” having content 10 20 30 40….., Store the result in “outBSAsce.dat”.
?For descending order: Read data from a file “inDesc.dat” having content 90 80 70 60…., Store the result in “outBSDesc.dat”.
?For random data: Read data from a file “inRand.dat” having content 55 66 33 11 44 …, Store the result in “outBSRand.dat”

Sample Input from file:
MAIN MENU (BINARY SEARCH)
1. Ascending Data
2. Descending Data
3. Random Data
4. ERROR (EXIT)

Output:
Enter option: 1
Before Sorting: Content of the input file
After Sorting: Content of the output file
Number of Comparisons: Actual
Scenario: Best or Worst-case
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 500

int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if target is present at mid
        if (arr[mid] == target)
            return mid;

        // If target is greater, ignore the left half
        if (arr[mid] < target)
            left = mid + 1;

        // If target is smaller, ignore the right half
        else
            right = mid - 1;
    }

    // Target not found
    return -1;
}

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
    printf("MAIN MENU (BINARY SEARCH)\n");
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
            outputFile = "outBSAsce.txt";
            break;
        case 2:
            inputFile = "inDesc.txt";
            outputFile = "outBSDesc.txt";
            break;
        case 3:
            inputFile = "inRand.txt";
            outputFile = "outBSRand.txt";
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
    mergeSort(arr, 0, n-1, &comparisons);
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
	
	int target =0;
	printf("Enter target to be found: ");
    scanf("%d", &target);

	start = clock();
    int num = binarySearch(arr, n, target );
    end = clock;
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    
	if(num==-1){
    	printf("target not found\n");
	}
	else{
		printf("target found at index %d\n",num);
	}

    printf("Execution Time: %lf seconds\n", time_taken);
    
}



