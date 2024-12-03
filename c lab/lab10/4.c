#include<stdio.h>
int main()
{
    int n,m;
    printf("enter n:");
    scanf("%d",&n);
    for(int i=1;i<=12;i++)
    {
       m=n*i;
       printf("%d * %d = %d \n",n,i,m); 
    }
    return 0;
}