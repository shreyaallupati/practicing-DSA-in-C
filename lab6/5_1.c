//5.1 Write a program to create a double linked list and perform the following menu based 
//operations on it:
//i. insert an element at specific position 
//ii. delete an element from specific position
// iii. Traverse the list

#include<stdio.h>
#include<malloc.h>

struct node{
	struct node *prev;
	int data;
	struct node *next;
};

struct node *start = NULL;
struct node * create_ll(struct node *start);
struct node * display(struct node *start);
struct node * insert_node(struct node *start);
struct node * delete_node(struct node *start);

int main(){
	
	struct node *start = NULL;
	start = create_ll(start);
	int choice;
	do{
		printf("\nMENU:");
		printf("\n1. insert an element at specific position \n2.delete an element from specific position \n3. Traverse the list");	
		printf("\nEnter choice:");
		scanf("%d",&choice);
		
		switch(choice){
		case 1:
			start = insert_node(start);
			break;
		case 2:
			start = delete_node(start);
			break;
		case 3:
			start = display(start);
			break;
		}	
	}
	while(choice!=4);

return 0;	
}


struct node *create_ll(struct node *start) {
    struct node *new_node, *ptr;
    int num;
    
    printf("\n Enter -1 to end");
    printf("\n Enter the data :");
    scanf("%d", &num);

    while (num != -1) {
        new_node = (struct node *)malloc(sizeof(struct node));
		
		new_node->prev = NULL;
        new_node->data = num;
        new_node->next = NULL;

        if (start == NULL) {
            start = new_node;
            new_node->next = NULL;
            new_node->prev = NULL;
        }
		else {
            ptr = start;

            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
			
            ptr->next = new_node;
            new_node->prev= ptr;
        }

        printf("\n Enter the data :");
        scanf("%d", &num);
    }

    return start;
}


struct node * insert_node(struct node * start)
{
	int pos,data,i;
	struct node *ptr,*temp;
	printf("enter the position to be inserted\n");
	scanf("%d",&pos);
	ptr=start;
	for(i=1;i<pos-1;i++)
	{
		ptr=ptr->next;
		
	}
	printf("enter data to be inserted\n");
	scanf("%d",&data);
	
	temp=(struct node*)malloc(sizeof(struct node));
	
    temp->data=data;
    temp->next=ptr->next;
    temp->prev=ptr;
    ptr->next=temp;
    ptr->next->prev=temp;
    
    return start;

}
	
	
struct node * delete_node(struct node * start)
{
	struct node *ptr,*temp1,*temp2;
	int pos,i;
	printf("enter the position to be deleted\n");
	scanf("%d",&pos);
	ptr=start;
	for(i=1;i<pos-1;i++)
	{
		ptr=ptr->next;
	}
	temp1=ptr->next;
	temp2=temp1->next;
	ptr->next=temp2;
	temp2->prev=ptr;
	free(temp1);
	
	return start;
}

struct node *display(struct node * start){
	struct node * ptr;
	ptr= start;
	while(ptr->next!=NULL){
		printf(" %d <=>",ptr->data);
		ptr=ptr->next;
	}
	printf(" %d",ptr->data);
	return start;
}
