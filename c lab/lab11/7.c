#include <stdio.h>
int main()
{
	int n, sum = 0;
	printf("Enter the value of n: ");
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		int x = 1;
		for(int j = 1; j <=i; j++)
		{
			x *= 2;
		}
		sum += x;
	}
	printf("Sum: %d\n", sum);
	return 0;
}