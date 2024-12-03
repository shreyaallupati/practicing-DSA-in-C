#include<stdio.h>
int main()
{
	int n,i,j,l=0,k,m;
	printf("Enter the size of the array.\n");
	scanf("%d",&n);
	int arr[n],arre[n],arro[n];
	for(i=0;i<n;i++)
	{
		printf("arr[%d] = ",i);
		scanf("%d",&arr[i]);
	}
	for(j=0;j<n;j++)
	{
		if(arr[j]%2==0)
		{
		arre[l]=arr[j];
		l++;
		}
	}
	printf("\n\n");
	printf("Even array is \n");
	for(m=0;m<l;m++)
	{
	printf("arr[%d] = %d\n",m,arre[m]);
	}
	l=0;
	for(j=0;j<n;j++)
	{
		if(arr[j]%2!=0)
		{
		arro[l]=arr[j];
		l++;
		}
	}
	printf("\n\n");
	printf("Odd array is \n");
	for(m=0;m<l;m++)
	{
	printf("arr[%d] = %d\n",m,arro[m]);
	}
	return 0;
}
