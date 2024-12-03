#include<stdio.h>
int main()
{
	int n,c=0,i,j,k,l,arr[n],arr1[n];
	printf("Enter the size of array.\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("arr[%d] = ",i);
		scanf("%d",&arr[i]);
	}
	for(int j=n-1;j>=0;j--)
	{
		arr1[c]=arr[j];
		c++;
	}
	printf("\n\n");
	for(int k=0;k<n;k++)
	{
		printf("arr[%d] = %d \n",k,arr1[k]);
	}
	return 0;
}
