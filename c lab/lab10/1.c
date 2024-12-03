#include<stdio.h>
int main()
{
    int n,r,p;
    int m=1;
    int t=1;
    printf("enter n: ");
    scanf("%d",&n);
    printf("enter r: ");
    scanf("%d",&r);
// permutation p= n!/(n-r)!
    for(int i=1;i<=n;i++)
    {
       // permutation p= m!/(m-t)!
       
       m=m*i;
    }
    for(int j=1;j<=(n-r);j++)
    {
       // permutation p= m!/(m-t)!
       
       t=t*j;
    }
 p=m/t;
 printf("nPr is %d",p);
 return 0;
 }