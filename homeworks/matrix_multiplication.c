#include<stdio.h>

int main(){
	
	int r1,c1,r2,c2;
	int i,j;
	printf("Enter the row and column of matrix a:");
    scanf("%d %d",&r1,&c1);

    printf("Enter the row and column of matrix b:");
    scanf("%d %d",&r2,&c2);
	
	if(c1 != r2){
        printf("Multiplication not possible since row2 is not equal to column 1 ");
        return 0;    
    }
	
	printf("Enter the values in matrix 1:");
	int **a;
	a= (int**)malloc(sizeof(int*)*r1);
    for(i = 0;i<r1;i++){
        a[i] = (int*)malloc(sizeof(int)*c1);
        for(j = 0;j<c1;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter the values in matrix 2:");
    int **b;
	b = (int**)malloc(sizeof(int*)*r2);
    for(i = 0;i<r2;i++){
        b[i] = (int*)malloc(sizeof(int)*c2);
        for(j = 0;j<c2;j++){
            scanf("%d",&b[i][j]);
        }
    }
    
    int c**;
    c= (int**)malloc(sizeof(int*)*r1);
    for(i = 0;i<r1;i++){
        c[i] = (int*)malloc(sizeof(int)*c2);
    }
    int k;
    for (i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            c[i][j] = 0;
  			for ( k = 0; k < r2; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
      
        }      
    }
    
    for(i = 0;i<r1;++i){
        for(j = 0;j<c2;++j){
            printf("%d ",c[i][j]);
        }
    }
    
    
}
