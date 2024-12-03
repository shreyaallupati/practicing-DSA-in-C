//3. WAP to find the smallest no from 3 inputted nu only using conditional operator with out using logical operator

#include<stdio.h>
int main()
{
int a,b,c;
printf("enter a,b,c:");
scanf("%d %d %d",&a,&b,&c);

((a < b) && (a < c)) ? printf("a is smallest\n") : 
   (b < c) ? printf("b is smallest\n") : 
	printf("c is smallest\n");

return 0;
}