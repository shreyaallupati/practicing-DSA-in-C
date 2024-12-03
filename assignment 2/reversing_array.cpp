// reversing of array
//assigment 2

#include<stdio.h>

int main(){
	int n=6;
	int a[n];
	int i;
	for(i=0;i<n;i++){
		scanf("%d ", &a[i]);
	}
	
	int temp;
	for(i=0;i<n/2;i++){
		temp= a[i];
		a[i]= a[n-i-1];
		a[n-i-1] = temp;
	}	
	for(i=0;i<n;i++){
		printf("%d ", a[i]);
	}
	return 0;
}

