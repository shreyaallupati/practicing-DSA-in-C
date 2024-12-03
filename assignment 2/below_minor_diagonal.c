//assignment 17

#include<stdio.h>

int main(){
	int a[4][4];
	printf("enter elements of the matrix: \n");
	int i,j;
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			int k=3;
			if(i+j>k){
				printf("%d ",a[i][j]);
			}
			else printf(" ");
		}
		printf("\n");
	}
	
	return 0;
}
