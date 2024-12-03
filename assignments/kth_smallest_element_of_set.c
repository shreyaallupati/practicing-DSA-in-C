#include<stdio.h>

void func(int a[], int n){
	int i;
	if(n==1){
		return;
	}
	for(i=0;i<n-1;i++){
		if(a[i]>a[i+1]){
			int temp = a[i];
			a[i] = a[i+1];
			a[i+1] = temp;
		}
	}
	func(a,n-1);
}

int main(){
	int n;
	printf("enter n \n");
	scanf("%d ",&n);
	
	int arr[n];
	
	int k;
	printf("enter k \n");
	scanf("%d ",&k);
	
	printf("enter array elements \n");
	int i;
	for(i=0;i<n;i++){
		scanf("%d ",&arr[i]);
	}
	func(arr,n);
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	
	printf("kth smallest element: %d",arr[k-1]);
	return 0;
}
