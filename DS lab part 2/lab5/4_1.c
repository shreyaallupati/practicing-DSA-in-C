// 4.1 4.2

#include<stdio.h>
#include<malloc.h>

struct node{
	int data;
	struct node *next;
};

struct node * start=NULL;
struct node * create_ll(struct node* start);
struct node * display(struct node* start);
struct node * insertnode(struct node* start);
struct node * deletenode(struct node* start);
struct node * countnode(struct node* start);
struct node * sort(struct node *start);
struct node * search(struct node *start);
struct node * reverse(struct node *start);

int main(){
	
    
	while(start==NULL)
	    start = create_ll(start);
	
	int option;

 	do{
	    printf("\nMENU:");
	    printf("\n 1. Insert the node at a position");
	    printf("\n 2. Delete a node from a specific position");
		printf("\n 3. count");
		printf("\n 4. Traversal");
		printf("\n 5. search");
		printf("\n 6. sort");
		printf("\n 7. reverse");
	    printf("\n Enter choice");
	    scanf("%d",&option);
	
	    switch(option)
	    {
	
	        case 1:
	  			start = insertnode(start);
	  			start= display(start);
	            break;
			case 2:
	        	start= deletenode(start);
	        	start= display(start);
	        	break;
			case 3:
				start = countnode(start);
	        	break;
			case 4:
	        	start= display(start);
	        	break;
	        case 5:
	        	start= search(start);
	        	break;
	    	case 6:
	        	start= sort(start);
	        	start= display(start);
	        	break;
			case 7:
	        	start= reverse(start);
	        	start= display(start);
	        	break;	    	
		}
	}while(option !=8);
	
	return 0;
}


struct node * create_ll(struct node * start){
	
	int d;
	struct node *newnode,*ptr;
	printf("\nenter -1 to end\n");
	printf("enter the element\n");
	scanf("%d",&d);
	while(d!=-1)
	{
	newnode= (struct node*)malloc(sizeof(struct node));
	newnode->data=d;
	newnode->next=NULL;
 		if(start==NULL)
	   {
	     newnode->next=NULL;
	     start=newnode;
	   }
	   else
	   {
	
	     ptr=start;
	
	     while(ptr->next != NULL)
	        ptr=ptr->next;
	
	     ptr->next=newnode;
	     newnode->next=NULL;
	    }
    	printf("enter the element\n");
		scanf("%d",&d);
	}
	return start;
}


struct node * display(struct node *start){
	struct node *ptr;
	ptr = start;
	while(ptr->next!=NULL){
		printf("%d-> ",ptr->data);
		ptr=ptr->next;
	}
	printf("%d \n",ptr->data);
	return start;
}


struct node * countnode(struct node *start){
	struct node *ptr;
	int count = 0;
	ptr = start;
	while(ptr!=NULL){
		ptr=ptr->next;
		count++;
	}
	printf("the total number of nodes : %d",count);
	return start;
}


struct node * insertnode(struct node *start){
	
	int n,data1,i;
	struct node *ptr,*ptr2;
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	ptr=start;
	printf("enter the position to insert\n");
	scanf("%d",&n);
	printf("enter the element to be inserted\n");
	scanf("%d",&data1);
	newnode->data=data1;
	for(i=1;i<n-1;i++)
	{
		ptr=ptr->next;
	}
	ptr2=ptr->next;
	ptr->next=newnode;
	newnode->next=ptr2;
	printf("node inserted \n");
}


struct node * deletenode(struct node *start){
	
	struct node *ptr1,*ptr2;
	int pos;
	printf("enter position: ");
	scanf("%d",&pos);
	
	int i;
	ptr1=start;
	for(i=0;i<pos-1;i++){
		ptr1=ptr1->next;
	}
	ptr2=ptr1->next->next;
	free(ptr1->next);
	ptr1->next=ptr2;
    
    printf("node deleted \n");
    return start;

}

struct node * reverse(struct node *start)
{

    struct node *pre,*current;
 
    if(start != NULL)
    {
        pre = start;
        current = start->next;
        start = start->next;
 
        pre->next = NULL; 
 
        while(start!= NULL)
        {
            start= start->next;
            current->next = pre;
 
            pre= current;
            current = start;
        }
        start = pre; 
    }
    printf("linked list reversed");
    return start;
}


struct node * search(struct node * start)
{	

	int i;
	struct node *ptr,*ptrx;
	ptr=start;
	int key;
	int c=0;
	int n = 0;
	
	ptrx = start;
	while(ptrx!=NULL){
		ptrx=ptrx->next;
		n++;
	}
		
	printf("enter element to be searched\n");
	scanf("%d",&key);
	
	for(i=1;i<n;i++)
	{
		if(ptr->data==key)
		{
			c++;
		}
		ptr=ptr->next;
    }
	if(c!=0)
	{
		printf("element found\n");
	}
	else
	{
		printf("element not present\n");
	}
	
	return start;
}



struct node * sort(struct node *start)
{	
	
	int i,j,k;
	int data;
	int n;
	struct node *temp1,*temp2,*ptrx;
	ptrx = start;
	while(ptrx!=NULL){
		ptrx=ptrx->next;
		n++;
	}
	for(i=n-2;i>=0;i--)
	{
		temp1=start;
		temp2=temp1->next;
		for(j=0;j<=i;j++)
		{
			if(temp1->data > temp2->data)
			{
				k=temp1->data;
				temp1->data=temp2->data;
				temp2->data=k;
			}
			temp1=temp2;
			temp2=temp2->next;
		}
	}
	printf("linked list sorted \n");
	return start;
}
