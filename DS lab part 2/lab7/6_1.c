/* 6.1 Write a menu driven program to create a stack using array and perform the following operation using function
a. Push
b. Pop
c. check stack is empty or not
d. check stack is full or not
e. display stack elements */

#include<stdio.h>
#include<string.h>
#define MAX 10

int top = -1;
int st[MAX];

void push(int st[],int val);
int pop(int st[]);
void IsEmpty(int st[]);
void IsFull(int st[]);
void traverse(int st[]);

int main(){
	int val;
	int choice;
	printf("\nMENU:");
	printf("\n1. Push \n2. Pop\n3. check stack is empty\n4. check stack is full\n5. display stack elements");
	
	do{
	scanf("%d",&choice);
	switch(choice){
		case 1:
			printf("\nenter value to be pushed in :");
			scanf("%d",&val);
			push(st,val);
			break;
		case 2:
			val=pop(st);
			if(val!=-1)
				printf("\n popped value : %d",val);
			break;
		case 3:
			IsEmpty(st);
			break;
		case 4:
			IsFull(st);
			break;
		case 5:
			traverse(st);
			break;
	}
	}while(choice<=5);
	
	return 0;
}


void push(int st[],int val){
	
	if(top==MAX-1){
		printf("\nStack overflow");
	}
	else{
		top++;
		st[top]= val;
	}
}


int pop(int st[]){
	if(top==-1){
		printf("\nStack empty");
	}
	else{
		top--;
		return(st[top+1]);
	}
}


void IsEmpty(int st[]){
	if(top==-1){
		printf("\nStack empty");
	}
	else{
		printf("\nStack is not empty");	
	}
}


void IsFull(int st[]){
	if(top==MAX-1){
		printf("\nStack is full");
	}
	else{
		printf("\nStack is not full");	
	}
}


void traverse(int st[]){
	int i;
	for(i = top; i >= 0; i --){
		printf("\n %d",st[i]);
	}
}
