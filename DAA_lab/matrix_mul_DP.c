#include <stdio.h>
#include <limits.h>

#define MAX 10

void print_optimal_parenthesization(int s[MAX][MAX], int i, int j);
void matrix_chain_order(int p[], int n);

int main()
{
    int n,i;
    int p[MAX];

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        int rows, cols;
        printf("Enter row and col size of A%d: ", i);
        scanf("%d %d", &rows, &cols);

        if (i == 1) {
            p[0] = rows;
        }
        p[i] = cols;
    }

    matrix_chain_order(p, n);

    return 0;
}

void matrix_chain_order(int p[], int n)
{
    int m[MAX][MAX] = {0};
    int s[MAX][MAX] = {0};
	int len, i, j, k;
    for (len = 2; len <= n; len++)
    {
        for (i = 1; i <= n - len + 1; i++)
        {
            j = i + len - 1;
            m[i][j] = INT_MAX;

            for ( k = i; k <= j - 1; k++)
            {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("\nM Table:\n");
    for ( i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (j < i)
                printf("0\t");
            else
                printf("%d\t", m[i][j]);
        }
        printf("\n");
    }

    printf("\nS Table:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (j <= i)
                printf("0\t");
            else
                printf("%d\t", s[i][j]);
        }
        printf("\n");
    }

    printf("\nOptimal parenthesization: ");
    print_optimal_parenthesization(s, 1, n);
    printf("\nThe optimal ordering of the given matrices requires %d scalar multiplications.\n", m[1][n]);
}

void print_optimal_parenthesization(int s[MAX][MAX], int i, int j)
{
    if (i == j)
    {
        printf("A%d", i);
    }
    else
    {
        printf("(");
        print_optimal_parenthesization(s, i, s[i][j]);
        printf(" ");
        print_optimal_parenthesization(s, s[i][j] + 1, j);
        printf(")");
    }
}
