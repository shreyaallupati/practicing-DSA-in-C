#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE* fptr;
	fptr = fopen("hello.txt","w");
	if(fptr==NULL){
		printf("file not opened");
		exit(0);
	}
	else{
		printf("opened");
	}
	return 0;
}
