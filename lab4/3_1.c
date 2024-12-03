#include<stdio.h>

// 3.1 WAP to perform transpose of a given sparse matrix in 3-tuple format.

void create(int s[15][3]){
	int i,x;
	printf("\nEnter no. of non-zero elements:");
	scanf("%d",&x);
	s[0][2]=x;
	for(i=1;i<=x;i++)
	{
	printf("\nEnter the next tuple (row,column,value):");
	scanf("%d %d %d",&s[i][0],&s[i][1],&s[i][2]);
	}
	return;
}

void trans(int s[15][3], int t[15][3])
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

void printt(int n[15][3]){
	int i,x;
	x=n[0][2];
	for(i=1;i<=x;i++)
	{
	printf("%d %d %d \n",n[i][0],n[i][1],n[i][2]);
	}
	return;
}


int main(){
	int sparse[15][3]; 
	int transpose[15][3];
	int m,n;
	printf("Enter the size of matrix (rows,columns):");
	scanf("%d%d",&m,&n);
	sparse[0][0]=m;
	sparse[0][1]=n;
	create(sparse);
	trans(sparse,transpose);
	printt(transpose);
	return 0;
}
