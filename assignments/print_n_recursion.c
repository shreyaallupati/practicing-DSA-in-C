#include <stdio.h>

void print(int n) {
    if (n <= 0) {
        return; // Base case: stop recursion when n becomes non-positive
    }
    
    // Print numbers in increasing order
    print(n - 1);
    printf("%d ", n);
}

int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    
    printf("Numbers from 1 to %d: ", n);
    print(n);
    printf("\n");
    
    return 0;
}

