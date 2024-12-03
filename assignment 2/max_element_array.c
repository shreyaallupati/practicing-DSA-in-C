//assignment 3

/* LA is a linear array with N elements. Write the
algorithm to finds the largest number and
counts the occurrence of the largest number */

#include<stdio.h>

int main(){
	int n=6;
	int a[n];
	int i;
	for(i=0;i<n;i++){
		scanf("%d ", &a[i]);
	}
	int max,c=0;
	for(i=0;i<n;i++){
		if(a[i+1]>a[i]){
			max= a[i+1];
			c++;
		}
	}	
	printf("%d %d",max,c);
	return 0;
}
