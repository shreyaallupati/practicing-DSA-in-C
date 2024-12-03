//WRITE A PROGRAM TO (bubble) SORT A SINGLY LINK LIST.
#include<stdio.h>
#include<malloc.h>

struct node
{
  int data;
  struct node *next;
};

struct node *start=NULL;
struct node * create_ll(struct node *);
struct node * display(struct node *);
struct node * sort_list(struct node *);

void main()
{
 int option;

 do
 {
        printf("\n****MAIN MENU****");
        printf("\n 1. create link list");
        printf("\n 2. Display link list");
        printf("\n 3. Sort a list");
        printf("\n 4. Exit");
        printf("\n Enter your option");
        scanf("%d",&option);

        switch(option)
        {

           case 1:
  
               start =create_ll(start);
               printf("\n link list created");
               break;


           case 2:
        
               start=display(start);
           
               break;

           case 3:

               start=sort_list(start);
               break;

        }
    
    }while(option !=4);

}

struct node * create_ll(struct node *start)
{

  struct node *new_node,*ptr;
  int num;
  printf("\n Enter -1 to end");
  printf("\n Enter the data :");
  scanf("%d",&num);

  while(num != -1)
  {

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
    printf("\n Enter the data :");
    scanf("%d",&num);
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

struct node * sort_list(struct node *start)
{
  struct node *ptr1,*ptr2;
  int temp;

  ptr1=start;
 
  while(ptr1->next != NULL)
  {

    ptr2=ptr1->next;
	while(ptr2 !=NULL)
    {

      if(ptr1->data > ptr2->data)
      {
        temp=ptr1->data;
        ptr1->data=ptr2->data;
        ptr2->data=temp;
      }
      ptr2=ptr2->next;
    }
  ptr1=ptr1->next;
 }
 return start;
}
