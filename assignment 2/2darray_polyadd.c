#include<stdio.h>

int main(){

	int m,n,i;
	printf("enter no of terms both polynomails 1,2 \n");
	scanf("%d %d",&m,&n);
			
	int a[2][m];
	int b[2][n];

/	printf("enter coefficients of polynomial 1 and its corresponding degree of x: ");
	for(i=0; i<m; i++)
	{
		scanf("%d %d",&a[0][i],&a[1][i]);
	}
	
	printf("\nenter coefficients of polynomial 2 and its corresponding degree of x: ");
	for(i=0; i<n; i++)
	{
		scanf("%d %d",&b[0][i],&b[1][i]);
	}
	int z=m+n;
	
	int c[2][z];
	
	for(i=0;i<z;i++){
		if(a[1][i]==b[1][i]){
			c[0][i] = a[0][i] + b[0][i];
			c[1][i] = a[1][i];
		}
		else if(a[1][i]> b[1][i]){
			c[0][i] = a[0][i];
			c[1][i] = a[1][i];
		}
		else{
			c[0][i] = b[0][i];
			c[1][i] = b[1][i];
		}
	}
	
	printf("\n\n");
	
	for(i=0; i<z; i++){
		printf("%dx^%d ",c[0][i],c[1][i]);
	}

	


}
