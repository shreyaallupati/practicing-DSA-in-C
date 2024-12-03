#include <stdio.h>
#include <string.h>

#define MAX 100

void find_LCS(char X[], char Y[], int m, int n);

int main()
{
    char X[MAX], Y[MAX];
    printf("Enter the first string into an array: ");
    scanf("%s", X);
    printf("Enter the second string into an array: ");
    scanf("%s", Y);

    int m = strlen(X);
    int n = strlen(Y);

    find_LCS(X, Y, m, n);

    return 0;
}

void find_LCS(char X[], char Y[], int m, int n)
{
    int L[MAX][MAX];
    int i,j;
    for (i = 0; i <= m; i++) {
        for ( j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = (L[i - 1][j] > L[i][j - 1]) ? L[i - 1][j] : L[i][j - 1];
        }
    }

    int index = L[m][n];
    printf("\nLCS Length: %d\n", index);

    char lcs[index + 1];
    lcs[index] = '\0';

    i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        } else if (L[i - 1][j] > L[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    printf("LCS: %s\n", lcs);
}
