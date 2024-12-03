#include <stdio.h>

int main(){
	int n;
	printf("enter number of elements: ");
	scanf("%d", &n);
    int arr[n];
    printf("enter the array elements: \n");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("array entered: ");
	for(int i=0;i<n;i++){
		printf("%d  ",arr[i]);
	}
    int temp;
    for(int i = 0; i<n/2; i++){
        temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
    }
    printf("\nreversed array: ");
    for(int i = 0; i < n; i++){
        printf("%d  ", arr[i]);
    }
    return 0;
}
