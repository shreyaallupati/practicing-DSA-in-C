#include<stdio.h>

//Write a menu driven program to create a structure to represent complex number and perform 
//the following operation using function :

struct complex
{
	int real;
	int img;
};
void add(struct complex n1,struct complex n2)
{
	int r=n1.real+n2.real;
	int i=n1.img+n2.img;
	printf("addition is : %d + %d i" ,r,i);
}
void mul(struct complex *n1,struct complex *n2)
{
	int r= n1->real*(n2->real) - n1->img*(n2->img);
	int i= n1->real*(n2->img) + n2->real*(n1->img);
	printf("multiplication is : %d + %d i",r,i);
}
int main()
{
	int choice;
	struct complex num1;
	struct complex num2;
	printf("enter complex number\n");
	scanf("%d \t %d",&num1.real, &num1.img);
	printf("enter complex number\n");
	scanf("%d \t %d",&num2.real, &num2.img);
	printf("enter the operation to be performed:\n 1. Addition \n 2. Multiplication \n");
	scanf("%d",&choice);
	if (choice==1)
	 add(num1,num2);
	else if (choice==2)
	 mul(&num1,&num2);
	else
	printf("enter valid input\n");
	return 0;
}
