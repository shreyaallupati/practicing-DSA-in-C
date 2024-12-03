//7.1 Write a menu driven program to create a linear queue using
// array and perform Enqueue, 
//Dequeue, Traverse, IsEmpty, IsFull operations.

#include<stdio.h>

#define MAX 10
int queue[MAX];
int front=-1;
int rear=-1;

void insert(void);
int delete(void);
void isFull(void);
void isEmpty(void);
void display(void);

void main()
{
 int val,option;


 do
 {
        printf("\n****MAIN MENU****");
        printf("\n 1. Insert an element");
        printf("\n 2. Delete an element");
        printf("\n 3. isEmpty");
        printf("\n 4. isFull");
        printf("\n 5. Display the queue");
        printf("\n 6. EXIT");
        printf("\n Enter your option");
        scanf("%d",&option);

        switch(option)
        {

           case 1:
				insert();
            	break;

			case 2:
        
               val=delete();
           
               if(val!=-1)
               printf("\n The deleted element from queue is : %d",val);
               break;

           case 3:
				isEmpty();
               break;
           case 4:
           		isFull();
           		break;
           case 5:
				display();
               break;

          
        }
    
    }while(option !=6);
     
}

 

void insert()
{

   int num;
   printf("\n Enter the number to be inserted in queue :");
   scanf("%d",&num);
  
   if(rear==(MAX-1))
   printf("\n Queue overflow");

   else if(front==-1 && rear==-1)
    { front=rear=0;
      queue[rear]=num;}

   else
    {rear++;
    queue[rear]=num;}
}


int delete()
{

  int val;
  if(front==-1 || front>rear)
  {
   printf("\nQueue underflow");
   return -1;
  }  

  else
  {
  
    val=queue[front];
    front++;
 
      if(front>rear)
       front=rear=-1;

   return val;
  }
}



void isFull()
{
	if(rear==(MAX-1))
		printf("\n Queue is full");
  	else
  		printf("\n Queue is not full");
}



void isEmpty()
{
	if(front==-1 || front>rear)
		printf("\n Queue is empty");
  	else
  		printf("\n Queue is not empty");
}



void display()
{
    int i;
    if(front==-1 || front>rear)
    {
     printf("\nQueue is empty");
    }  

  else
  {
    for(i=front;i<=rear;i++)
      printf("\t%d",queue[i]);
  }
}

