#include<stdio.h>
#include<malloc.h>

struct node
{
  int data;
  struct node *next;
};

struct node *start=NULL;
struct node *start1= NULL;
struct node * create_ll(struct node * start);
struct node * display(struct node * start);
struct node * alt_ll(struct node * start, struct node *start1);

int main()
{
 int option;

 do
 {
    printf("\n****MAIN MENU****");
    printf("\n 1. create link list");
    printf("\n 2. Display link list");
	printf("\n 3. create alt ll");
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
        	start1 =alt_ll(start,start1);
        	struct node *temp= start;
        	while(temp->next!=NULL){
        		start1 = alt_ll(temp,start1);
        		temp=temp->next->next;
        		}
        	
        	break;
		}
    
    }
	while(option !=3);

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


struct node * alt_ll( struct node * start, struct node *start1){
	
	struct node *new_node=(struct node *)malloc(sizeof(struct node));
	new_node->next=NULL;
	
	struct node *ptr,*ptr1;
	
    if(start1==NULL){
    	start1=new_node;
    	start1->data = start->data;
    	start1->next = NULL;
   	}
   	
    else{
    	ptr = start;
    	ptr1 = start1;
    	
    	while(ptr->next!=NULL && ptr1->next!=NULL){
	    	new_node->data =ptr->next->next->data;
	    	ptr=ptr->next;
	    	ptr1->next = new_node;
			new_node->next= NULL;
		}
		
	} 
	
	display(start1);
	
	return start1;
}
