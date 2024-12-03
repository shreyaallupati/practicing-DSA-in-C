#include<stdio.h>
#include<stdlib.h>

// Write a program to create an array of n elements using dynamic memory allocation. Calculate sum of all the prime elements of the array using function and de-allocate the memory of the array after its use.

int prime(int a){
	if (a==1){
		return 0;
	}
	if(a==2){
		return 1;
	}
	for(int i=2;i<a/2;i++){
		if(a%i==0){
			return 0;
		}
	}
	return 1;
}
int main(){
	int n;
	int *p;
	printf("\n enter size of array: ");
	scanf("%d",&n);
	p = (int *)calloc(n,sizeof(int));
	printf("\n Enter array elements: ");
	for(int i=0;i<n;i++){
		scanf("%d",p+i);
	}
	int sum=0;
	for (int  i = 0; i < n; i++)
    {
        if (prime(*(p+i))==1 )
        {
            sum=sum+*(p+i);
        }
        
    }
    printf("sum = %d",sum);
	return 0;
		
}