#include<stdio.h>
#include<malloc.h>

struct node
{
  int data;
  struct node *next;
};

struct node *start=NULL;
struct node * create_ll(struct node * start);
struct node * display(struct node * start);
struct node * swap(struct node * start);

int main()
{
 int option;

 do
 {
    printf("\n****MAIN MENU****");
    printf("\n 1. create link list");
    printf("\n 2. Display link list");
	printf("\n 3. Exit");
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
        
            start=swap(start);
        	break;
		}
    
    }
	while(option !=4);

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


struct node * swap(struct node * start){
	int a,b;
	printf("enter position a to be swapped with b");
	scanf("%d %d",&a,&b);
	
	struct node * ptr1, *ptr2, *temp, *prev1, *prev2;
	int i;
	for(i=0;i<a;i++){
	    prev1 = ptr1;
		ptr1= ptr1->next;
	}
	for(i=0;i<b;i++){
	    prev2 = ptr2;
		ptr2= ptr2->next;
	}
	prev1->next = ptr2;
	prev2->next = ptr1;
	temp = ptr1->next;
	ptr1->next = ptr2->next;
	ptr2->next = temp;
	
	start = display(start);
	
	return start;
}
