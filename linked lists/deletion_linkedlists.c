//WRITE A PROGRAM TO DELETE A GIVEN NODE OF SINGLY LINK LIST.
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
struct node * delete_beg(struct node *);
struct node * delete_node(struct node *);

void main()
{
 int option;

 do
 {
        printf("\n****MAIN MENU****");
        printf("\n 1. create link list");
        printf("\n 2. Display link list");
        printf("\n 3. Delete a node");
        printf("\n 4. Exit");
        printf("\n Enter your option");
        scanf("%d",&option);

        switch(option)
        {

           case 1:
  
               start=create_ll(start);
               printf("\n link list created");
               break;


           case 2:
        
               start=display(start);
           
               break;

           case 3:

               start=delete_node(start);
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


struct node * delete_beg(struct node *start)
{

  struct node *ptr;

     ptr=start;
     start=start->next;
     free(ptr);

 return start;
}


struct node * delete_node(struct node *start)
{

  struct node *ptr,*preptr;
  int val;

  printf("\n Enter the value of the node which has to be deleted :");
    scanf("%d",&val);
 
     ptr=start;
     
     if(ptr->data==val)
     {
        start=delete_beg(start);
        return start;
     }
     else
     {
         while(ptr->data != val)
         {
           preptr=ptr;
           ptr=ptr->next;
         }

        preptr->next=ptr->next;
        free(ptr);

      return start;
    }
}
