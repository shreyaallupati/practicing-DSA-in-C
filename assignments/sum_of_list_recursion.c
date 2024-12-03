#include<stdio.h>

int sum(int arr[], int n) {
    if (n == 0) {
        return 0; // Base case: empty array
    } 
	else {
        return arr[n - 1] + sum(arr, n - 1);
    }
}

int main(){
	
	int n;
	printf("enter n \n");
	scanf("%d ",&n);
	
	int arr[n];
	
	printf("enter array elements \n");
	int i;
	for(i=0;i<n;i++){
		scanf("%d ",&arr[i]);
	}
	
	printf("sum = %d",sum(arr,n));
	return 0;
	
}
