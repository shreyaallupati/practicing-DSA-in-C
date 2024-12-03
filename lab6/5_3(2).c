//5.3 Write a program to represent the given sparse matrix
//using header single linked list and display it

#include<stdio.h>
#include<malloc.h>

struct node
{
  int row;
  int column;
  int value;
  struct node *next;
};


struct node *start=NULL;
struct node *end=NULL;
struct node * create_ll(int r,int c,int v);
struct node * display(struct node * start,int count);

int main()
{
int m,n;

printf("enter size of sparse matrix: ");
scanf("%d %d",&m,&n);
int mat[m][n];
printf("enter elements of sparse matrix: ");
int i,j;
int count=0;
for(i=0;i<m;i++){
for(j=0;j<n;j++){
scanf("%d", &mat[i][j]);
}
}

for(i=0;i<m;i++){
for(j=0;j<n;j++){
if(mat[i][j]!=0){
count ++;
}
}
}
start = create_ll(m,n,count);

for(i=0;i<m;i++){
    for(j=0;j<n;j++){
       if(mat[i][j]!=0){
        start = create_ll(i,j,mat[i][j]);
    }
    }
    }
start = display(start,count);
return 0;
}


struct node * create_ll(int r,int c,int v)
{
    struct node *new_node=(struct node *)malloc(sizeof(struct node));
   
    new_node->row=r;
    new_node->column=c;
    new_node->value =v;
    new_node->next=NULL;
   
    if(start==NULL){
    start=new_node;
    end=new_node;
    }
   
    else{
    end->next = new_node;
    end= new_node;
        }
   
return start;
}


struct node * display(struct node *start,int count)
{
if(start == NULL){
printf("linked list empty");
return start;
}
struct node *ptr;
ptr=start;

while(ptr != NULL)
{
int i;
    for (i = 0; i < count+1 ; i++){
printf("\t %d",ptr->row);
printf("\t %d",ptr->column);
printf("\t %d\n",ptr->value);
ptr=ptr->next;
}
}
return start;
}
