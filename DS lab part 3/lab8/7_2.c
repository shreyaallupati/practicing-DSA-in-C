//Write a menu driven program to implement linear queue operations such as Enqueue, Dequeue,  IsEmpty, Traverse using single linked list.

#include<stdio.h>
#include<malloc.h>

struct node
{
  int data;
  struct node *next;
};

struct node *start=NULL;
struct node * enqueue(struct node *);
struct node * display(struct node *);
struct node * dequeue(struct node *);
struct node * isEmpty(struct node *);

void main()
{
 int option;
 do
 {
        printf("\n****MAIN MENU****");
        printf("\n 1. enqueue");
        printf("\n 2. Dequeue");
        printf("\n 3. isEmpty");
        printf("\n 4. Display queue");
        printf("\n 5. Exit");
        printf("\n Enter your option");
        scanf("%d",&option);

        switch(option)
        {

           case 1:
  
               start=enqueue(start);
               
               break;


           case 2:
        
               start=dequeue(start);
           
               break;

           case 3:

               start=isEmpty(start);
               break;
            case 4:

               start=display(start);
               break;
        }
    
    }while(option !=5);

}

struct node * enqueue(struct node *start)
{

  struct node *new_node,*ptr;
  int num;
  printf("\n Enter the data :");
  scanf("%d",&num);
   new_node=(struct node *)malloc(sizeof(struct node));
   new_node->data=num;

   if(start==NULL)
   {
     new_node->next=NULL;
     start=new_node;
   }
   else
   {

     ptr=start;

     while(ptr->next != NULL)
        ptr=ptr->next;

     ptr->next=new_node;
     new_node->next=NULL;
}

 return start;
}



struct node * display(struct node *start)
{
  struct node *ptr;
  ptr=start;

  while(ptr != NULL)
  {

    printf("\t %d",ptr->data);
    ptr=ptr->next;
  }
  return start;
}



struct node * dequeue(struct node *start)
{

  struct node *ptr;

     ptr=start;
     start=start->next;
     free(ptr);

 return start;
}


struct node * isEmpty( struct node * start){
	if(start==NULL){
		printf("\nqueue is empty");
	}
	else{
		printf("queue is not empty");
	}
	return start;
}
