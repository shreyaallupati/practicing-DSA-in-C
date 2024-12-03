#include<stdio.h>
int hcf(int *a,int *b)
{
	int h;
	if(a < b)
	 for(int i=1;i<= *a;i++)
	 	if( *a %i == 0 && *b %i == 0)
	 	h=i;
	else
	 for(int i=1;i<= *b;i++)
	 	if(*a % i == 0 && *b % i == 0)
	 	h=i;
	 return h;
}
int main()
{
	int hcf(int *a ,int *b);
	int x,y;
	printf("Enter 2 numbers.\n");
	scanf("%d%d",&x,&y);
	printf("The HCF of %d and %d is %d.\n",x,y,hcf(&x,&y));
	return 0;
}
