#include <stdio.h>

#define MAX 2

void multiply(int a[MAX + 1][2], int m, int b[MAX + 1][2], int n, int c[MAX * 2 + 1][2]) {
    int i,j;
	for (i = 0; i <= m; i++) {
        for ( j = 0; j <= n; j++) {
            c[i + j][0] += a[i][0] * b[j][0];
            c[i + j][1] = a[i][1] + b[j][1];
        }
    }
}

int main() {
    int m, n;
	int i;
    printf("Enter the degree of the first polynomial: ");
    scanf("%d", &m);
    
    printf("Enter the degree of the second polynomial: ");
    scanf("%d", &n);

    printf("Enter the coefficients and exponents of the first polynomial:\n");
    int a[MAX + 1][2];
    for ( i = 0; i <= m; i++) {
        scanf("%d %d", &a[i][0], &a[i][1]);
    }

    printf("Enter the coefficients and exponents of the second polynomial:\n");
    int b[MAX + 1][2];
    for ( i = 0; i <= n; i++) {
        scanf("%d %d", &b[i][0], &b[i][1]);
    }

    int c[MAX * 2 + 1][2] = {{0}};

    multiply(a, m, b, n, c);

    printf("Resulting polynomial after multiplication:\n");
    for ( i = 0; i <= m + n; i++) {
        printf("%d x^%d  ", c[i][0], c[i][1]);
    }

    return 0;
}
