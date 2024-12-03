#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


void enqueBeg();
void enqueEnd();
void delqueBeg();
void delqueEnd();
void display();
int deque[5];
int front=-1;
int rear=-1;


void main()
{
	int ch;
	do
	{
	printf("\nPress 1. insert at the beginning.");
	printf("\nPress 2. insert at the end.");
	printf("\nPress 3. delete from the beginning.");
	printf("\nPress 4. delete from the end.");
	printf("\nPress 5. display data.");
	printf("\nPress 6. exit from the output screen.");
	printf("\nEnter your choice:\n");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:enqueBeg();
	break;
	case 2:enqueEnd();
	break;
	case 3:delqueBeg();
	break;
	case 4:delqueEnd();
	break;
	case 5:display();
	break;
	case 6:exit(0);
	default:printf("\nYou have entered wrong choice!.");
	}
	}while(ch!=6);
	getch();
}


void enqueBeg()
{
	int value,i;
	if(front==0 && rear==4)
	{
		printf("\nDeque is full.");
	}
	else
	{
		printf("\nEnter the data to be added at the beginning:");
		scanf("%d",&value);
		if(front==-1)
		{
			front=rear=0;
			deque[front]=value;
		}
		/*If deque is full from the front only*/
		else if(front==0 && rear!=4)
		{
			/*Shift the elements from 1 position to
			its right.*/
			for(i=rear;i>=front;i--)
			{
				deque[i+1]=deque[i];
			}
			rear++;
			deque[front]=value;
		}
		/*If deque is empty from the front.*/
		else if(front>0)
		{
			front--;
			deque[front]=value;
		}
		printf("\nNumber inserted at the beginning is %d",deque[front]);
	}
}


void enqueEnd(){
	int value,i;
	if(front==0 && rear==4)
	{
		printf("\nDeque is full.");
	}
	else
	{
		printf("\nEnter the data to be added at the end:\n");
		scanf("%d",&value);
		if(rear==-1)
		{
			front=rear=0;
			deque[rear]=value;
		}
		/*If deque is full from the end only*/
		else if(front!=0 && rear==4)
		{
			/*Shift the elements from 1 position to
			its left.*/
			for(i=front;i<=rear;i++)
			{
				deque[i-1]=deque[i];
			}
			front--;
			deque[rear]=value;
		}
		/*If deque is empty from the end.*/
		else if(rear<4)
		{
			rear++;
			deque[rear]=value;
		}
		printf("\nNumber inserted at the end is %d",deque[rear]);
	}
}


void delqueBeg()
{
	int value;
	if(front==-1)
	{
		printf("Deque is empty.");
	}
	else
	{
		if(front==rear)
		{
			value=deque[front];
			front=rear=-1;
		}
		else
		{
			value=deque[front];
			front++;
		}
	}
	printf("\nNumber deleted from the beginning is %d",value);
}


void delqueEnd()
{
	int value;
	if(rear==-1)
	{
		printf("Deque is empty.");
	}
	else
	{
		if(front==rear)
		{
			value=deque[rear];
			front=rear=-1;
		}
		else
		{
			value=deque[rear];
			rear--;
		}
	}
	printf("\nNumber deleted from the end is %d",value);
}


void display()
{
	int i;
	if(front==-1 || rear==-1)
	{
		printf("Deque is empty.");
	}
	else
	{
		for(i=front;i<=rear;i++)
		{
			printf("%5d",deque[i]);
		}
	}
}

