#include<stdio.h>
int main()
{
	int m,n,c=0,d=1;
	int i,j;
	printf("enter row and column of matrix ");
	scanf("%d%d",&m,&n);
	int a[m][n];
	printf("Enter elements of sparse matrix \n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j]){
				c++;
			}
		}
	}
	int b[c+1][3];
	b[0][0]=m;
	b[0][1]=n;
	b[0][2]=c;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i][j])
			{
				b[d][0]=i;
				b[d][1]=j;
				b[d][2]=a[i][j];
				d++;
			}
		}
	}
	printf("optimized matrix is\n");
	for(i=0;i<=c;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d ",b[i][j]);
		}
		printf("\n");
	}
	return 0;
}

