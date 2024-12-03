#include<stdio.h>
int main()
{
	int i,a,b,n,m;
	printf("Enter the size of the square matrix.\n");
	scanf("%d%d",&m,&n);
	int arr[m][n];
	i=2;
	for(a=0;a<m;a++)
	 for(b=0;b<n;b++)
	 {
	  arr[a][b]=i;
	  i+=2;
	 }
	for(a=0;a<m;a++)
	 {
	  for(b=0;b<n;b++)
	   printf("%d  ",arr[a][b]);
           printf("\n");
	 }
	for(a=0;a<m;a++)
	{
	 for(b=0;b<n;b++)
	   if(a!=b)
	   printf("%d  ",arr[a][b]);
	   else
	   printf("    ");
	 printf("\n");
	}
    return 0;
}
