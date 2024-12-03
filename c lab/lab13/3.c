#include<stdio.h>
int main()
{
	int n,temp,i,j,k,l;
	printf("Enter the size of array.\n");
	int arr[n];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("arr[%d] = ",i);
		scanf("%d",&arr[i]);
	}
	k=n;
	printf("\n");
	for(j=0;j<k;j++)
	{
		temp=arr[k-1];
		arr[k-1]=arr[j];
		arr[j]=temp;
		k--;
	}
	for(i=0;i<n;i++)
	{
	printf("arr[%d] = %d\n",i,arr[i]);
	}
	return 0;
}