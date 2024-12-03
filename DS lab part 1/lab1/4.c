#include<stdio.h>

int main(){
    int arr[5];
    for(int i=0; i<5; i++){
        scanf("%d",&arr[i]);
    }
    printf("the array made is:");
    for(int i=0; i<5; i++){
        printf("%d ",arr[i]);
    }

    printf("enter 0th element: ");
    for(int i=5; i>=0; i--)
    {
        arr[i] = arr[i-1];
        if (arr[i] == arr[0]){
            scanf("%d",&arr[0]);
        }
    }
    
    printf("the new array made is:");
    for(int i=0; i<=5; i++){
        printf("%d ",arr[i]);
    }
    return 0;

}