//assignment 11
//Write an algorithm that takes as input the size of the array and the elements
//in the array and a particular index and prints the element at that index.

#include<stdio.h>

void algo(int n,int arr[],int index){
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("%d",arr[index]);
}

int main(){
	int n,index;
	int a[n];
	scanf("%d",&n);
	scanf("%d",&index);
	algo(n,a,index);
	return 0;
	
}
