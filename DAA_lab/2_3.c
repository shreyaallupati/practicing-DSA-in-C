#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 256

int calculateBinaryLength(int n) {
    int length = 0;
    while (n > 0) {
        n /= 2;
        length++;
    }
    return length;
}

// Function to convert a decimal number to its binary representation
int ToBinary(int n) {
    // Base case
    if (n == 0) {
        return 0;
    }
    
    // Recursive call
    int binary = ToBinary(n / 2);
    
    // Append the current bit to the binary result
    return binary * 10 + (n % 2);
}

int main()
{
	FILE *inputFile, *outputFile;
    int n,i;
    int numbers[50];
    int binary[50];
    printf("enter the number od decimals to be converted in binary");
    scanf("%d",&n);
    
    inputFile = fopen("inDec.txt", "r");
    if (inputFile == NULL) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    // Read integers from the input file
    for (i = 0; i < n; i++) {
        if (fscanf(inputFile, "%d", &numbers[i]) != 1) {
            printf("Error: Failed to read the specified number of integers.\n");
            fclose(inputFile);
            return EXIT_FAILURE;
        }
    }
    fclose(inputFile);
    
     for(i=0;i<n;i++)
     {
     	 binary[i]=ToBinary(numbers[i]);
	 }
	 // Open the output file for writing
    outputFile = fopen("inBin.txt", "w");
    if (outputFile == NULL) {
        perror("Error opening output file");
        return EXIT_FAILURE;
    }

    // Write the results to the output file
    fprintf(outputFile, "The content of the binary array: ");
    int j;
    for (j = 0; j < n; j++) {
        fprintf(outputFile, "Binary of %d is %d \n", numbers[j] ,binary[j]);
    }
    printf("binary values are printed in output file \n");
    return 0;
}
