#include<stdio.h>

/*2.1 WAP to create a 1-D array of n elements and perform the following menu based operations 
using function.
a. insert a given element at specific position.
b. delete an element from a specific position of the array.
c. linear search to search an element
d. traversal of the array */


void insert(int *arr,int *size)
{
	int insert,pos,i;
	printf("element to be inserted\n");
	scanf("%d",&insert);
	printf("enter position\n");
	scanf("%d",&pos);
	for(i=*size;i>=pos;i--){
		arr[i]=arr[i-1];	
	}
	arr[pos]= insert;
	(*size)++;
	printf("final array: \n");
	for(i=0;i<*size;i++){
		printf("%d ",arr[i]);
	}
}
void Delete(int *arr,int *size)
{
	int pos,i;
	printf("enter position to be deleted\n");
	scanf("%d",&pos);
	for(i=pos;i<*size-1;i++){
		arr[i]=arr[i+1];	
	}
	(*size)--;
	printf("final array: \n");
    for(i=0;i<*size;i++){
		printf("%d ",arr[i]);
    }
}
    
void ls(int *arr,int *size)
{
	int ls,i;
	int pos=-1;
	printf("element to be searched\n");
	scanf("%d",&ls);
	for(i=0;i<*size;i++){
		if(arr[i]==ls)
			pos=i;
	}
	if(pos!=-1)
		printf("element is present at position %d",pos);
	else
		printf("the element does not exist");
}

void traverse(int *arr,int *size)
{
	int i;
	printf("elements in the array are:\n");
	for(i=0;i<*size;i++)
	{
		printf("%d ",arr[i]);
	}
}
int main()
{
	int n,i, choice;
	printf("enter the size of the array\n");
	scanf("%d",&n);
	int arr[n];
	printf("enter the elements\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("elements in the array are:\n");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n***MENU***\n");
	printf("1.Insert \n2.Delete \n3. Linear Search \n4. Traverse \n5. Exit");
	while(choice!=5)
	{
		printf("\n enter your choice\n");;
		scanf("%d",&choice);
		if (choice==1)
			insert(arr,&n);
		else if (choice==2)
			Delete(arr,&n);
		else if(choice==3)
			ls(arr,&n);
		else if(choice==4)
			traverse(arr,&n);
	}
	return 0;
}
