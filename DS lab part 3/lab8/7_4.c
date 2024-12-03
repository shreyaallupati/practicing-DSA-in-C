//7.4 Implement size limited queue.

#include<stdio.h>

#define MAX 5
int queue[MAX];
int front=-1;
int rear=-1;

void insert(void);
void delete(void);
int peek(void);
void display(void);
int isFull(void);

void main()
{
 int val,option;


 do
 {
        printf("\n****MAIN MENU****");
        printf("\n 1. Insert an element");
        printf("\n 2. Delete an element");
        printf("\n 3. PEEK");
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
        
               delete();
           
               //if(val!=-1)
               //printf("\n The deleted element from queue is : %d",val);
               break;

           case 3:

               val=peek();
           
               if(val!=-1)
               printf("\n The first value in queue is : %d",val);
               break;

           case 4:

               display();
               break;

          
        }
    
    }while(option !=5);
     
}

 

void insert()
{

   int num;
   printf("\n Enter the number to be inserted in queue :");
   scanf("%d",&num);
   
   if(rear == (MAX-1)){
   	int i;
   	queue[rear]=num;
    for(i=1; i< MAX-1; i++){
    	queue[i]=queue[i+1];
	}
	rear++;
	
    }
   	    
   if(front==-1 && rear==-1)
    { 
	front=rear=0;
    queue[rear]=num;
	}

   else
    {
	rear++;
    queue[rear]=num;
	}
}


void delete()
{

  int val;
  if(front==-1 || front>rear)
  {
   printf("\nQueue underflow");
   return;
  }  

  else
  {
  
    //val=queue[front];
    front++;
 
      if(front>rear)
       front=rear=-1;

   return ;
  }
}

int peek()
{

  if(front==-1 || front>rear)
  {
   printf("\nQueue is empty");
   return -1;
  }   
  else
  
   return(queue[front]);
  
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


int isFull(){
	int val;
	if(front ==-1 && rear == MAX-1){
		val =1;
	}
	else val=0;
	return val;
}
