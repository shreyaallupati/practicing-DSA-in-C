#include<stdio.h>
#include<malloc.h>

struct node
{
	int data;
	struct node *prev;
	struct node *next;
};

struct node *start=NULL;
struct node * create_ll(struct node *);
struct node * display(struct node *);

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
		}
    
    }
	while(option !=3);

}

struct node *create_ll(struct node *start) {
    struct node *new_node, *ptr;
    int num;
    
    printf("\n Enter -1 to end");
    printf("\n Enter the data :");
    scanf("%d", &num);

    while (num != -1) {
        new_node = (struct node *)malloc(sizeof(struct node));

        new_node->data = num;
        new_node->next = start;

        if (start == NULL) {
            start = new_node;
            new_node->next = start;
        }
		else {
            ptr = start;

            while (ptr->next != start) {
                ptr = ptr->next;
            }

            ptr->next = new_node;
        }

        printf("\n Enter the data :");
        scanf("%d", &num);
    }

    return start;
}

struct node * display(struct node *start)
{
  struct node *ptr;
  ptr=start;

  while(ptr->next != start)
  {
	printf("\t %d",ptr->data);
    ptr=ptr->next;
  }
  printf("\t %d",ptr->data);
  return start;
}

