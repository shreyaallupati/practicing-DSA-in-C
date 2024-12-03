//assignment 10

#include<stdio.h>

int main(){
	int a[5][5];
	printf("enter elements of lower triangular matrix: ");
	int i,j;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(i<=j)
				a[i][j] = a[j][i];
			else a[i][j] = 0;
		}
	}
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
