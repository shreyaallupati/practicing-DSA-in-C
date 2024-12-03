int fact(int *a)
{
int f=1;
for(int i=1;i<=*a;i++)
f*=i;
return f;
}
#include<stdio.h>
#include<stdlib.h>
int main()
{
int n,r,k;
int fact(int *a);
printf("Enter the values of n and r.\n");
scanf("%d%d",&n,&r);
if(n<r)
{
printf("Invalid Input.\n");
exit(0);
}
k=n-r;
int npr=fact(&n)/fact(&k);
printf("Permutation is : %d\n",npr);
int ncr=fact(&n)/(fact(&r)*fact(&k));
printf("Combination is : %d\n",ncr);
return 0;
}
