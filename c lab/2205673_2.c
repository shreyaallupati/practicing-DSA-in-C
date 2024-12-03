//Store the Fibonacci numbers in a matrix of 3X3 and display in reverse order.

#include<stdio.h>
int main()
{
    int t1=0;
    int t2=1;
    int tt=0;
    int i,j,temp,n=1;
    int arr[3][3];
    for(i=3;i>=0;i--)
    {
        for(j=3;j>=0;j--)
        {
            do{
             
             t1=t2;
             tt=t1+t2;
             t2=tt;
             arr[i][j]=tt;
             n++;
            }
            while(n<=9);
            
        }
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
        
    
    return 0;
}