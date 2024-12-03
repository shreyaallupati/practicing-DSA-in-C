#include<stdio.h>
int main()
{
	int i,j,m,n,p,q,a=0;
    int arr2[p][q];
    int arr1[m][n];
	printf("Enter the size of the array 1.\n");
	scanf("%d%d",&m,&n);
	printf("Enter the size of the array 2.\n");
	scanf("%d%d",&p,&q);

	if(m==p&&n==q)
	{

		printf("Enter the elements of array 1. \n");
	for(i=0;i<m;i++)
	 for(j=0;j<n;j++)
		scanf("%d",&arr1[i][j]);
	
	printf("Enter the elements of array 2. \n");
	for(i=0;i<p;i++)
	 for(j=0;j<q;j++)
		scanf("%d",&arr2[i][j]);

	 for(i=0;i<p;i++)
	  for(j=0;j<q;j++)
	    	 if(arr1[i][j]==arr2[i][j])
	 	 a+=1;
	 if(a==(m*n))
	 printf("Equal Arrays.\n");
	 else
	 printf("Unequal Arrays.\n");
	}
	else
	printf("Unequal Arrays.\n");
	return 0;
}