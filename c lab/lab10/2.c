#include<stdio.h>
int main()
{
    int n,r,c;
    int m=1;
    int t=1;//let t=(n-r)
    int y=1;
    printf("enter n: ");
    scanf("%d",&n);
    printf("enter r: ");
    scanf("%d",&r);
// combination c= n!/((n-r)!*r!)
    for(int i=1;i<=n;i++)
    {
       // combination c=m!/((m-t)!t!)
       m=m*i;
    }
    for(int j=1;j<=(n-r);j++)
    {
       // cmbination c= m!/((m-t)!t!)
       t=t*j;
    }
    for(int j=1;j<=r;j++)
    {
       // combination c= m!/((m-t)!t!)
       y=y*j;
    }
 c=m/(t*y);
 printf("nCr is %d",c);
 return 0;
 }