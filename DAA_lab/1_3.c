#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number in the given range
int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    int N, Min, Max;

    srand(time(0));

    printf("Enter the size of the list (N): ");
    scanf("%d", &N);

    printf("Enter the minimum value (Min): ");
    scanf("%d", &Min);

    printf("Enter the maximum value (Max): ");
    scanf("%d", &Max);

    int randomNumbers[N];

    printf("Generated random numbers:\n");
    int i;
    for (i = 0; i < N; i++) {
        randomNumbers[i] = getRandomNumber(Min, Max);
        printf("%d ", randomNumbers[i]);
    }
    printf("\n");

    return 0;
}

