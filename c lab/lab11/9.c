#include<stdio.h>
int main()
{
    int n,x,sum=0;
    printf("enter n: ");
    scanf("%d",&n);
    printf("enter x: ");
    scanf("%d",&x);

    for(int i=0;i<n;i++)
    {
        int m=1;
        for(int j=0;j<=i;j++)
        {
            m=m*x;
        }
        if(j%2==0)
        {
        sum=sum-m;
        }
        if(j%2==1)
        {
         sum=sum+m;
        }
    }
    printf(" 1 - x + x^2 - x^3... n = %d",(sum/x));
    return 0;
}