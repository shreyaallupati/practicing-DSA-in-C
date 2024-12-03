#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
}*START=NULL;

void insb(struct node *);
void inse(struct node *);
void delb(struct node *);
void dele(struct node *);

void main()
{
	struct node *p,*temp;
	int num;
	printf("for terminate type any negative number\n");
	printf("enter data\n");
	scanf("%d",&num);
	while(num>=0)
	{
		p=malloc(sizeof(struct node));
		if(START==NULL)
		{
			START=p;
			p->next=NULL;
			p->data=num;
		}
		else
		{
			temp=START;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=p;
			p->data=num;
			p->next=NULL;
		}
		printf("enter data\n");
		scanf("%d",&num);
	}
	temp=START;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=START;
	char ch;
	printf("enter B for insertion at begin\nenter I for insertion at end\nenter A for deletion at begin\nenter C for deletion at end\n");
	scanf(" %c",&ch);
		switch(ch)
		{
			case 'B':insb(START);
			break;
			case 'I':inse(START);
			break;
			case 'A':delb(START);
			break;
			case 'C':dele(START);
			break;
		}
	
}

void insb(struct node *head)
{
	struct node *new,*temp;
	temp=head;
	new=malloc(sizeof(struct node));
	printf("enter new data\n");
	scanf("%d",&new->data);
	while(temp->next!=head)
	{
		temp=temp->next;
	}
	new->next=head;
	head=new;
	temp->next=head;
	temp=head;
	while(temp->next!=head)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("%d",temp->data);
}

void inse(struct node *head)
{
	struct node *new,*temp;
	new=malloc(sizeof(struct node));
	printf("enter new data\n");
	scanf("%d",&new->data);
	temp=head;
	while(temp->next!=head)
	{
		temp=temp->next;
	}
	temp->next=new;
	new->next= START;
	temp=head;
	while(temp->next!=head)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("%d",temp->data);
}
	
void delb(struct node *head)
{
	struct node *temp,*last;
	temp=head;
	while(temp->next!=head)
	{
		temp=temp->next;
	}
	last=temp;
	temp=head;
	head=temp->next;
	last->next=head;
	temp=head;
	while(temp->next!=head)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("%d",temp->data);
}

void dele(struct node *head)
{
	struct node *temp,*del;
	temp=head;
	while(temp->next->next!=head)
	{
		temp=temp->next;
	}
	del=temp->next;
	temp->next=head;
	free(del);
	temp=head;
	while(temp->next!=head)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("%d",temp->data);
}
