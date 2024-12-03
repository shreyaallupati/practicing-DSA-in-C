#include<stdio.h>
int main()
{
	int n,temp,i,j,l;
	printf("Enter the size of array.\n");
	int arr[n];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("arr[%d] = ",i);
		scanf("%d",&arr[i]);
	}
	printf("\n");
	if(n%2==0)
	l=n;
	else
	l=n-1;
	for(j=0;j<l;j+=2)
	{
		temp=arr[j+1];
		arr[j+1]=arr[j];
		arr[j]=temp;
	}
	for(i=0;i<n;i++)
	{
	printf("arr[%d] = %d\n",i,arr[i]);
	}
	return 0;
}
