#include<stdio.h>

void largest(int *arr,int n)
{
    int i;
    for(i=1;i<n;i++)
    {
        if(*arr<*(arr+i))
        {
            *arr=*(arr+i);
        }
    }
    printf("largest number is %d",*arr);
}

int main()
{
    int arr[5];
    printf("input an array \n");
    int i=0;
    for(;i<5;i++)
    {
        printf("arr[%d]= ",i);
        scanf("%d",&arr[i]);
    }
    largest();
    return 0;
}