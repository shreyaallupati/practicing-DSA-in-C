//parenthesis check

#include<stdio.h>
#include<string.h>
#include<conio.h>

#define MAX 10

int stk[MAX];
int top=-1;

char pop();
void push(char);

void main()
{
	char exp[MAX]; int temp,i,flag=1;

	printf("\n Enter an expression");
    scanf("%s",exp);

	for(i=0;i<strlen(exp);i++)
   {

		if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
       
		    push(exp[i]);

	    if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
	    {
	
	        if(top==-1)
	        	   flag=0;
	
	        else
	        {
	            temp=pop();
	
	            if(exp[i]==')' && (temp=='{' || temp=='['))
	                flag=0;
	
	            if(exp[i]=='}' && (temp=='(' || temp=='['))
	                flag=0;
	
	            if(exp[i]==']' && (temp=='(' || temp=='{'))
	                flag=0;
	    	}

    	}
	}


	if(top>=0)
		flag=0;

	if(flag==1)
		printf("\n Valid expression");

	else
		printf("\n Invalid expression"); 
 
}


void push(char c)
{
	if(top==(MAX-1))
		printf("\nStack overflow");

	else
	{
    	top++;
    	stk[top]=c;
	}
}

char pop()
{
	char c;
	if(top==-1)
		printf("\nStack underflow");
  	else
  		c=stk[top];
	top--; 
	return c;
}

