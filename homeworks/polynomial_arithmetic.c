#include<stdio.h>

int main()
{
	int m,n;
	printf("enter degree of both polynomails 1,2 \n");
	scanf("%d %d",&m,&n);
	
	int a[m];
	int b[n];
	
	printf("enter coefficients of polynomial 1: ");
	for(int i=m-1; i>=0; i--){
		scanf("%d",&a[i]);
	}
	printf("enter coefficients of polynomial 2: ");
	for(int i=n-1; i>=0; i--){
		scanf("%d",&b[i]);
	}
	
	int z;
	if(m>n){
		z=m;
	}
	else{
		z=n;
	}
	
	printf("\nthe given arrays are: \n")
	for(int i=m-1; i>=0; i--){
		printf("%d ",a[i]);
	}
	printf("\n");
	
	for(int i=n-1; i>=0; i--){
		printf("%d ",b[i]);
	}
	printf("\n");
	
	int sum[z];
	int diff[z];
	
	for(int i=0; i<z; i++){
		sum[i]= a[i] + b[i];
		diff[i] = b[i] - a[i];
	}
	
	printf("sum of the given polynomials(coefficients) 1+2: \n");
	for(int i=z-1; i>=0; i--){
		printf("%d ",sum[i]);
	}
	
	printf("\ndifference of the given polynomials(coefficients) 2-1: \n");
	for(int i=z-1; i>=0; i--){
		printf("%d ",diff[i]);
	}
		
	int mul[m+n-1];
	
	for(int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            mul[i+j] += a[i]*b[j];
        }
    }
	printf("\nproduct of the given polynomials(coefficients) 1*2: \n");
	for(int i=m+n-1; i>=0; i--){
		printf("%d ",mul[i]);
	}
	
	return 0;
	
}
