//CIRCULAR LL AND ITS OPERATIONS

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
        printf("\n 1. create circular link list");
        printf("\n 2. Display circular link list");
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

    printf("%d->",ptr->data);
    ptr=ptr->next;
  }
  printf("%d",ptr->data);
  printf("->");
   
  return start;
}

struct node * insertBegin( struct node *start){
    
    int data;
    printf("Enter the data\n");
    scanf("%d",&data);
    
    struct node * newNode= (struct node *)malloc(sizeof(struct node));
    newNode->data=data;
    
    struct node *ptr=start;

    while (ptr->next!= start)
    {
        ptr=ptr->next;
    }
    ptr->next=newNode;
    newNode->next=start;
    start= newNode;

    return  start ;
}

struct node * insertLast(struct node *start){

    int data;
    printf("Enter the data\n");
    scanf("%d",&data);

    struct node * newNode= (struct node *)malloc(sizeof(struct node));
    newNode->data=data;

    struct node *ptr=start;

    while (ptr->next!= start)
    {
        ptr=ptr->next;
    }
    ptr->next=newNode;
    newNode->next=start;

    return start;    
}

struct node * deleteLast(struct node * start){

    struct node *ptr=  start;
    struct node *prev;

    while (ptr->next!= start)
    {
        prev=ptr;
        ptr=ptr->next;
    }
    prev->next=start;
    free(ptr);    

    return start;   
}

struct node *deleteFirst(struct node *start) {

    if (start == NULL) {
        printf("List is empty. Cannot delete.\n");
        return start;
    }

    struct node *ptr = start;
    
    while (ptr->next != start) {
        ptr = ptr->next;
    }

    ptr->next = start->next;
	free(start);
	start=ptr->next;

    return start;
}





struct node * insertAfter(struct node *start){

    struct node * ptr=start;
    struct node *temp;

    int data;
    printf("Enter the data after which you want to put the number \n");
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
    temp=ptr->next; // store the ptr next node in temp 
    ptr->next=newNode;// change the next pointer of present pointer to new Node
    newNode->next= temp; // set the pointer of the newNode to temp that we previously stored in temp

    return start;    
}

struct node * insertBefore(struct node * start){
    
	struct node *ptr=start;
    struct node *prev=NULL; // initially null

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
      prev=ptr;
      ptr=ptr->next;
    }
    prev->next=newNode;
    newNode->next=ptr;
    
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
    struct node *prev=NULL;

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

     while (ptr->next->data!=data)
    {
      prev=ptr;
      ptr=ptr->next;
    }
    prev->next=ptr->next;
    //ptr->next=NULL;
    free(ptr);

    return start;
}


struct node * deleteNode(struct node * start){

    int data;
    printf("Enter the data\n");
    scanf("%d",&data);
    
    struct node *ptr= start;
    struct node *prev;

    if (start->data==data)
    {
        start=deleteFirst(start);
        return start;

    }
    
    while (ptr->data!=data)
    {
        prev=ptr;
        ptr=ptr->next;
    }

    prev->next=ptr->next;
    free(ptr);

    return start;
}
_
