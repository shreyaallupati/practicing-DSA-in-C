#include<stdio.h>
void add(int b1[15][3],int b2[15][3], int sum[15][3] )

{
   
	int t1,t2,i,j,k;
	   
	t1=b1[0][2];
	t2=b2[0][2];
	   
	i=j=k=0;
	   
	sum[0][0]=b1[0][0];
	sum[0][1]=b1[0][1];
	   
	while(i<=t1&&j<=t2)
	{
	    if(b1[i][0]<b2[j][0])      
	    {
		    sum[k][0]=b1[i][0];
		    sum[k][1]=b1[i][1];
		    sum[k][2]=b1[i][2];
		    k++;
		    i++;
		}
	       
		else if(b2[j][0]<b1[i][0])      
		{
		    sum[k][0]=b2[j][0];
			sum[k][1]=b2[j][1];
			sum[k][2]=b2[j][2];
		    k++;
			j++;	       
		}
		       
		else if(b1[i][1]<b2[j][1])      
		{
		    sum[k][0]=b1[i][0];
		    sum[k][1]=b1[i][1];
		    sum[k][2]=b1[i][2];
		    k++;
		    i++;
	    }
		       
		else if(b2[j][1]<b1[i][1])      
		{
		    sum[k][0]=b2[j][0];
			sum[k][1]=b2[j][1];
			sum[k][2]=b2[j][2];
			k++;
			j++;
		}
		       
		else
		{
			sum[k][0]=b1[i][0];      
			sum[k][1]=b1[i][1];
			sum[k][2]=b1[i][2]+b2[j][2];
			k++;
			i++;
			j++;
		}
	}
	   
	while(i<=t1)     
	{
	    sum[k][0]=b1[i][0];
		sum[k][1]=b1[i][1];
		sum[k][2]=b1[i][2];
		i++;
		k++;
	}
	   
	while(j<=t2)        
	{
	    sum[k][0]=b2[j][0];
		sum[k][1]=b1[j][1];
		sum[k][2]=b1[j][2];
		j++;
		k++;
	}
	   
	sum[0][2]=k-1;       
}


int main()
{
	int i,t1,t2,m1,m2,n1,n2,n,j;
	int s1[15][3],s2[15][3],sum[15][3];
	
	printf("\nEnter no. of non-zero elements for matrix 1:");
	scanf("%d",&t1);
	printf("Enter the number of rows and coloumns\n");
	scanf("%d%d",&m1,&n1);
	
	s1[0][0]=m1;
	s1[0][1]=n1;
	s1[0][2]=t1;
	
	printf("\nEnter the tuple(row,column,value):");
	for(i=1;i<=t1;i++)
	{
		scanf("%d%d%d",&s1[i][0],&s1[i][1],&s1[i][2]);
	}
	
	printf("\nEnter no. of non-zero elements for 2nd matrix:");
	scanf("%d",&t2);
	printf("Enter the number of rows and coloumns\n");
	scanf("%d%d",&m2,&n2);
	
	s2[0][0]=m2;
	s2[0][1]=n2;
	s2[0][2]=t2;
	
	printf("\nEnter the next tuple(row,column,value):");
	for(i=1;i<=t2;i++)
	{
		scanf("%d%d%d",&s2[i][0],&s2[i][1],&s2[i][2]);
	}
	
	add(s1,s2,sum);
	
	printf("sum of the given two matrices is \n");
	n =sum[0][2];
	for(i=0;i<n+1;i++){
		for(j=0;j<3;j++){
			printf("%d \t",sum[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
