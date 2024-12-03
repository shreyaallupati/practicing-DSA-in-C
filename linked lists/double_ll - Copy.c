//DOUBLE LL AND ITS OPERATIONS

#include<stdio.h>
#include<malloc.h>

struct node
{
	struct node *prev;
	int data;
	struct node *next;
};

struct node *start=NULL;

struct node * create_ll(struct node *);
struct node * display(struct node *);
struct node * insertAfter(struct node *);
struct node * insertBefore(struct node *);
struct node * deleteAfter(struct node *);
struct node * deleteBefore(struct node *);
struct node * insertBegin(struct node *);
struct node * insertLast(struct node *);
struct node * deleteLast(struct node*);
struct node * deleteFirst(struct node *);
struct node * deleteNode(struct node *);


void main()
{
 int option;

 do
 {
        printf("\n****MAIN MENU****");
        printf("\n 1. create double link list");
        printf("\n 2. Display double link list");
        printf("\n 3. Insert begining");
        printf("\n 4. Insert Last");
        printf("\n 5. Delete First");
        printf("\n 6. Delete Last");
        printf("\n 7.Insert After");
        printf("\n 8.Insert Before");
        printf("\n 9.Delete After");
        printf("\n 10.Delete Before");
        printf("\n 11.Delete Node");
        printf("\n 12.Exit");

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
				start=insertBegin(start);
            	break;
			case 4:
            	start = insertLast(start);
            	break;
        	case 5:
            	start=deleteFirst(start);
            	break;
        	case 6:
            	start = deleteLast(start);
            	break;
			case 7:
            	start= insertAfter(start);
            	break;
            case 8:
            	start= insertBefore(start);
            	break;
            case 9:
            	start=deleteAfter(start);
            	break;
        	case 10:
                start=deleteBefore(start);
                break;
			case 11:
                start=deleteNode(start);
                break;
				
		}
    
    }while(option !=12);

}


struct node *endptr(struct node *start) {
    struct node *new_node, *ptr, *end;
    ptr=start;
    while(ptr->next!=NULL){
    	ptr=ptr->next;
	}
	end = ptr;
	return end;
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


struct node * display(struct node *start)
{
  struct node *ptr;
  ptr=start;

  while(ptr->next != NULL)
  {

    printf("%d->",ptr->data);
    ptr=ptr->next;
  }
  printf("%d",ptr->data);
   
  return start;
}

struct node * insertBegin( struct node *start){
    
    int data;
    printf("Enter the data\n");
    scanf("%d",&data);
    
    struct node * new_node= (struct node *)malloc(sizeof(struct node));
    new_node->data=data;
    
    struct node *ptr=start;
	
	new_node->next=start;
	start->prev= new_node;
	new_node->prev = NULL;
    start= new_node;

    return  start ;
}

struct node * insertLast(struct node *start){

    int data;
    printf("Enter the data\n");
    scanf("%d",&data);

    struct node * new_node= (struct node *)malloc(sizeof(struct node));
    new_node->data=data;

    struct node *ptr=start;

    struct node *end = endptr(start);
    end->next = new_node;
    new_node->prev=end;
    new_node->next=NULL;
    end=new_node;

    return start;    
}

struct node * deleteLast(struct node * start){
	
	struct node *temp;
    struct node *end= endptr(start);
	temp = end->prev;
    temp->next=NULL;
	free(end); 
	end = temp;

    return start;   
}

struct node *deleteFirst(struct node *start) {

    if (start == NULL) {
        printf("List is empty. Cannot delete.\n");
        return start;
    }

    struct node *temp;
	
	temp = start->next;
	temp->prev = NULL;
	free(start);
	start = temp;
	
    return start;
}





struct node * insertAfter(struct node *start){

    struct node *ptr=start;
    struct node *temp;

    int data;
    printf("Enter the data AFTER which you want to put the number \n");
    scanf("%d",&data);
    printf("Enter the data \n");
    int data1;
    scanf("%d",&data1);

   
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data= data1;


    while (ptr->data!=data )
    {
        ptr=ptr->next;
    }

	temp= ptr->next;
	ptr->next=newNode;
	newNode->prev=ptr;
	newNode->next= temp;
	temp->prev=newNode; 

    return start;    
}

struct node * insertBefore(struct node * start){
    
	struct node *ptr=start;
    struct node *temp;

    int data;
    printf("Enter the number before which you want to put\n");
    scanf("%d",&data);
    printf("Enter the data \n");
    int data1;
    scanf("%d",&data1);


    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data= data1;


    while (ptr->data!=data)
    {
      ptr=ptr->next;
    }
    
	temp = ptr->prev;
	ptr->prev= newNode;
	newNode->next=ptr;
	newNode->prev = temp;
	  
    return start;
}


struct node* deleteAfter(struct node *start){

    if (start==NULL)
    {
		printf("Empty linked list\n");
	}
    
    struct node * ptr=start;
    struct node *temp;

    int data;
    printf("Enter the number after which you want to delete the node\n");
    scanf("%d",&data);
   
	while (ptr->data!=data)
	{
		ptr=ptr->next;
	}
	temp=ptr->next; // Store the next node of ptr to temp 
	temp->prev=ptr->prev;
	
	
    if(temp==start){ // if the ptr-> next is start that means it is cycle so delete the start;
        start=deleteFirst(start);
        return start;
	}
   ptr->next=ptr->next->next;
     
   free(temp);
   
  return start;
}

struct node * deleteBefore( struct node * start){
   
   if (start==NULL)
    {
      printf("Empty linked list\n");

    }
    
    struct node * ptr=start;
    struct node *end = endptr(start);
    struct node *temp;

    int data;
    printf("Enter the number before which you want to delete the node\n");
    scanf("%d",&data);

    if (ptr->data==data)
    {
      start=deleteLast(start);
      return start;

    }
    if (ptr->next->data==data)
    {
      start= deleteFirst(start);
      return start;
    }    

     while (end->data!=data)
    {
      ptr=ptr->prev;
    }
	temp=ptr->prev;
	ptr->next=temp;
	
    free(ptr);

    return start;
}


struct node * deleteNode(struct node * start){

    int data;
    printf("Enter the data\n");
    scanf("%d",&data);
    
    struct node *ptr= start;
    struct node *temp;

    if (start->data==data)
    {
        start=deleteFirst(start);
        return start;

    }
    
    while (ptr->data!=data)
	{
        ptr=ptr->next;
    }
    temp=ptr->prev;
    temp->next=ptr->next;
    ptr->next=temp;
    ptr->next->prev=temp;
    
	free(ptr);

    return start;
}

