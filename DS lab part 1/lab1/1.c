#include<stdio.h>

// WAP to swap 2 values using call by value and call by reference

void swap_v(int a, int b){
    int temp;
    temp = a;
    a = b;
    b = temp;
    
    printf(" a = %d, b= %d \n",a,b);
    return;
}

//call by reference
void swap_r(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return;
}

int main(){
    int a,b;
    printf("enter values of a and b \n");
    scanf("%d %d", &a, &b);

    swap_v(a,b);
    
    
    printf("enter values of a and b \n");
    scanf("%d %d", &a, &b);

    swap_r(&a,&b);
    printf(" a = %d, b = %d \n",a,b);
    
    
    return 0;
}