#include<stdio.h>
int main()
{
	int n;
	printf("Enter the size of array.\n");
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
	{
		printf("arr[%d] = ",i);
		scanf("%d",&arr[i]);
	}
	for(int j=0;j<n;j++)
	{
		if(arr[j]%2==0)
		arr[j]=0;
		else
		arr[j]=1;
	}
	printf("\n\n");
	for(int k=0;k<n;k++)
	{
		printf("arr[%d] = %d\n",k,arr[k]);
	}
	return 0;
}	