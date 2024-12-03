//Write a program to implement a circular queue

#include<stdio.h>

#define MAX 5
int queue[MAX];
int front=-1;
int rear=-1;

void insert(void);
int delete(void);
void isEmpty(void);
void isFull(void);
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
        printf("\n 4. Display the queue");
        printf("\n 5. EXIT");
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
  
   if((front==0 && rear==(MAX-1))||(front==rear+1))
   printf("\n Queue overflow");

   else if(front==-1 && rear==-1)
   {
     front=rear=0;
     queue[rear]=num;
   }

   else if(front!=0 && rear==MAX-1)
   {
     rear=0;
     queue[rear]=num;
   }

   else
   {
     rear++;
     queue[rear]=num;
   }
}


int delete()
{

  int val;
  if(front==-1 && rear==-1)
  {
   printf("\nQueue underflow");
   return -1;
  }  
  
  val=queue[front];

  if(front==rear)
    front=rear=-1;

  else
  {
  
      if(front==MAX-1)
       front=0;
      
      else
       front++;
  }
   return val;
}


void isEmpty(){
	if(front==-1 && rear==-1)
    {
   		printf("\nQueue is empty");
   }  
   else printf("\n Queue is not empty");
}

void isFull(){
	if((front==0 && rear==(MAX-1))||(front==rear+1))
    {
   		printf("\nQueue is full");
   }  
   else printf("\n Queue is not full");
}


void display()
{
    int i;
    if(front==-1 && rear==-1)
    {
     printf("\nQueue is empty");
    }  

  else
  {

    if(front<rear)
    {
      for(i=front;i<=rear;i++)
      printf("\t%d",queue[i]);
    }
    else
    {
      for(i=front;i<MAX;i++)
      printf("\t%d",queue[i]);

      for(i=0;i<=rear;i++)
      printf("\t%d",queue[i]);
    }
  }
}
