//program 7

#include<stdio.h>
int main()
{
    int a,b,c;
    int *p1,*p2,*p3;
    int temp1;
    p1=&a;
    p2=&b;
    p3=&c;
    printf("enter a,b,c \n");
    scanf("%d%d%d",p1,p2,p3);
    temp=*p1;
    *p1=*p2;
    *p2=*p3;
    *p3=temp;
    printf("after swap: a=%d,b=%d,c=%d",a,b,c);
    return 0;
}
