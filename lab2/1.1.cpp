#include<stdio.h>

//1.1 Write a program to read two numbers and compare the numbers using function call by address.

void compare(int *a,int *b){
	if(*a>*b){
		printf("%d is greater than %d \n",*a,*b);
	}
	if(*a==*b){
		printf("both numbers are same\n");
	}
	else{
		printf("%d is smaller than %d \n",*a,*b);
	}
	
}

int main(){
	int a,b;
	printf("enter two numbers: \n");
	scanf("%d %d",&a,&b);
	compare(&a,&b);
	return 0;
}
