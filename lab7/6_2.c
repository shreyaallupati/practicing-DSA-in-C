/* 6.2 Write a menu driven program to create a stack using linked list and perform the following operation using function
a. Push
b. Pop
c. IsEmpty
d. display the stack elements */

#include<stdio.h>
#include<malloc.h>


struct node{
	int data;
	struct node *next;
};


struct node *top = NULL;
struct node * push( struct node *,int);
struct node * pop ( struct node *);
struct node * IsEmpty(struct node *);
struct node * display(struct node *);


int main(){
	struct node * top = NULL;
	int val;
	int choice;
	
	do{
	printf("\nMENU:");
	printf("\n1. Push \n2. Pop\n3. check stack is empty\n4. display stack elements");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			printf("\nenter value to be pushed in :");
			scanf("%d",&val);
			top = push(top,val);
			break;
		case 2:
			top=pop(top);
			break;
		case 3:
			top=IsEmpty(top);
			break;
		case 4:
			top=display(top);
			break;
	}
	}while(choice<=4);
	
	return 0;
}

struct node * push(struct node * top,int val){
	struct node * new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = val;
	
	if(top==NULL){
		top= new_node;
		new_node->next = NULL;
	}
	else
	{	
		new_node -> next = top;
		top = new_node;
	}
	return top;
}


struct node *pop(struct node *top)
{
	struct node *ptr;
	ptr = top;
	if(top == NULL)
		printf("\n STACK UNDERFLOW");
	else
	{
		top = top -> next;
		printf("\n The value being deleted is: %d", ptr -> data);
		free(ptr);
	}
	return top;
}



struct node * display(struct node *top){
	struct node *ptr;
	ptr= top;
	if(top == NULL)
		printf("\n STACK IS EMPTY");
	else{
		while(ptr!=NULL){
			printf("\n %d",ptr->data);
			ptr=ptr->next;
		}
	}
	return top;
}



struct node *IsEmpty(struct node *top){
	if(top==NULL){
		printf("\NSTACK IS EMPTY");
	}
	else 
		printf("STACK IS NOT EMPTY");
}
