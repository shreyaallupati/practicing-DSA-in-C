//2.4

#include <stdio.h>
#include <stdlib.h>

// Function to compute GCD using recursion
int gcd(int a, int b) {
    if (b == 0)
        return a;
        
    return gcd(b, a % b);
}

int main() {
	
    FILE *sourceFile = fopen("inGcd.txt", "r");
    if (sourceFile == NULL) {
        perror("Error opening source file");
        return 1;
    }

    FILE *destFile = fopen("outGcd.txt", "w");
    if (destFile == NULL) {
        perror("Error opening destination file");
        fclose(sourceFile);
        return 1;
    }

    int num1, num2;
    while (fscanf(sourceFile, "%d %d", &num1, &num2) == 2) {
        int result = gcd(num1, num2);
        printf("Read numbers: %d and %d, GCD: %d\n", num1, num2, result); // Debugging line
        fprintf(destFile, "The GCD of %d and %d is %d\n", num1, num2, result);
    }

    fclose(sourceFile);
    fclose(destFile);

    return 0;
}
