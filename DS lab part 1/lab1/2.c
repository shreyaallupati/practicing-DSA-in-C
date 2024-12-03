//wap to input and display the values along with the sum of all values using dma to a pointer variable

#include<stdio.h>
#include<stdlib.h>

int main(){
    int *a;
    int sum = 0;
    a=(int *)malloc(5*sizeof(int));
    printf("enter a 5 element array:");
    for(int i=0; i<5; i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<5;i++){
       sum += a[i]; 
    }
    printf("the array is as follows: \n");
    for(int i=0; i<5; i++){
        printf("%d ",a[i]);
    }
    printf("the sum of the given elements array is= %d",sum);
    return 0;
}