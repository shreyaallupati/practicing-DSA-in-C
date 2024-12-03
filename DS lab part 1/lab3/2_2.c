#include<stdio.h>

/* 2 Write a program to perform the following operations on a given square matrix using 
functions: 
i. Find the no.of nonzero elements
ii. Display upper triangular matrix
iii. Display the elements of just above and below the main diagonal */

int main(){
	printf("enter the size of square matrix \n");
	int n;
	int a[n][n];
	
	scanf("%d",&n);
	int i,j;
	printf("enter the elements of square matrix of order nxn: ");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d ",&a[i][j]);
		}
	}
	
	//no of non zero elements:
	int count=0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(a[i][j]!=0){
				count++;
			}
		}
	}
	printf("non zero elements: %d",count);
	printf("\n\n");
	//upper triangular matrix:
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			int k = i+j;
			if(i<=j){
				printf("%d",a[i][k-i]);
			}
			else{
				printf(" ");
			}		
		}
		printf("\n");
	}
	printf("\n\n");
	//elements above the diagonal:
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(j>i){
				printf("%d",a[i][j]);
			}
			else{
				printf(" ");
			}
		}
		printf("\n");
	}
	printf("\n\n");
	//elements below the diagonal
	for(i=0;i<n;i++){
		for(j=0;j<i;j++){
			if(i>j){
				printf("%d",a[i][j]);
			}
			else{
				printf(" ");
			}
		}
		printf("\n");
	}
	
	return 0;
}
