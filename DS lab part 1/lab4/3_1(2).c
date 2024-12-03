#include<stdio.h>
void create(int s[100][3])
{
	int i,t;
	printf("\nEnter no. of non-zero elements:");
	scanf("%d",&t);
	s[0][2]=t;
	for(i=1;i<=t;i++)
	{
	printf("\nEnter the next triple(row,column,value):");
	scanf("%d%d%d",&s[i][0],&s[i][1],&s[i][2]);
	}
}
void trans(int s[100][3], int t[100][3])
{
	int i,j,k,n;
	t[0][0]=s[0][1];
	t[0][1]=s[0][0];
	t[0][2]=s[0][2];
	k=1;
	n=s[0][2];
	for(i=0;i<s[0][1];i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i==s[j][1])
			{
				t[k][0]=i;
				t[k][1]=s[j][0];
				t[k][2]=s[j][2];
				k++;
			}
		}
	}
}
void printt(int t[100][3])
{
	int i,n;
	n=t[0][2]; //no of 3-triples
	printf("\nAfter Transpose:\n");
	printf("\nrow\t\tcolumn\t\tvalue\n");
	for(i=0;i<=n;i++)
	printf("%d\t\t%d\t\t%d\n",t[i][0],t[i][1],t[i][2]);
	}
	
void prints(int s[100][3])
	{
	int i,n;
	n=s[0][2]; //no of 3-tuples
	printf("\nrow\t\tcolumn\t\tvalue\n");
	for(i=0;i<=n;i++)
	printf("%d\t\t%d\t\t%d\n",s[i][0],s[i][1],s[i][2]);
	}
	
	
int main(){
	int m,n;
	int sparse[100][3],transpose[100][3];
	printf("Enter the size of matrix (rows,columns):");
	scanf("%d%d",&m,&n);
	sparse[0][0]=m;
	sparse[0][1]=n;
	create(sparse);
	prints(sparse);
	trans(sparse,transpose);
	printt(transpose);
	return  0;
		
}
