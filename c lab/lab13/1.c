#include<stdio.h>
int main()
{
	int n,arr[n];
	printf("Enter the size of array.\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("arr[%d] = ",i);
		scanf("%d",&arr[i]);
	}
	
	printf("\n\n");
	
	for(int j=n-1;j>=0;j--)
	{
		printf("arr[%d] = %d \n",j,arr[j]);
	}
	return 0;
}
