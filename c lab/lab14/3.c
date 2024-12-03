#include<stdio.h>
int main()
{
	int i,j,m,n,temp,a,b;
	int arr[m][n];

	printf("Enter the size of the array. \n");
	scanf("%d%d",&m,&n);
	
	printf("ENter the array 1 elements.\n");
	for(i=0;i<m;i++)
	 for (j=0;j<n;j++)
	  scanf("%d",&arr[i][j]);

	printf("Enter the choice[1] or [2]\n");
	scanf("%d",&b);
	if(b==1)
	{
	  a=n;
	  for(i=0;i<m;i++)
	   for (j=0;j<n/2;j++)
	   {
	      temp=arr[i][j];
	      arr[i][j]=arr[i][n-1];
	      arr[i][n-1]=temp;
	   }
	for(i=0;i<m;i++)
	{
	 for (j=0;j<n;j++)
	 printf("%d",arr[i][j]);
	 printf("\n");
	}
	}
	if(b==2)
	{
	  a=m;
	  for(i=0;i<m/2;i++)
	   for (j=0;j<n;j++)
	   {
	      temp=arr[i][j];
	      arr[i][j]=arr[m-1][j];
	      arr[m-1][j]=temp;
	   }
	for(i=0;i<m;i++)
	{
	 for (j=0;j<n;j++)
	 printf("%d",arr[i][j]);
	 printf("\n");
	}
	}
	return 0;
}
