#include<stdio.h>
int main()
{
	int n,nn,c=0;
	printf("Enter the size of the 2 arrays.\n");
	scanf("%d%d",&n,&nn);
	int arr1[n],arr2[nn];
	int arr3[n+nn];
	for(int i=0;i<n;i++)
	{
		printf("arr[%d] = ",i);
		scanf("%d",&arr1[i]);
	}
	for(int j=0;j<nn;j++)
	{
		printf("arr[%d] = ",j);
		scanf("%d",&arr2[j]);
	}
	for(c;c<n;c++)
	arr3[c]=arr1[c];
	for(;c<(n+nn);c++)
	arr3[c]=arr2[c-n];
	for(int k=0;k<(n+nn);k++)
	{
		printf("arr[%d] = %d\n",k,arr3[k]);
	}
	return 0;
}