#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,j,m,n,p,q,k;
	printf("Enter the size of the array 1.\n");
	scanf("%d%d",&m,&n);
	int a[m][n];	
	printf("Enter the elements of array 1. \n");
	for(i=0;i<m;i++)
	 for(j=0;j<n;j++)
		scanf("%d",&a[i][j]);
	printf("Enter the size of the array 2.\n");
	scanf("%d%d",&p,&q);
	int b[p][q];
	int c[p][q];
	printf("Enter the elements of array 2. \n");
	for(i=0;i<p;i++)
	 for(j=0;j<q;j++)
		scanf("%d",&b[i][j]);
	for(i=0;i<m;i++)
	for(j=0;j<q;j++)
	{
	c[i][j] = 0;
	for(k=0;k<n;k++)
	c[i][j] = c[i][j]+a[i][k]*b[k][j];
	}
	printf("Multiplication of matrices is : \n");
	for(i=0;i<m;i++)
	{
	for(j=0;j<q;j++)
	printf("%d ",c[i][j]);
	printf("\n");
	}
	return 0;
}
