#include<stdio.h>
#include<limits.h>
#define MAX 100

int idx = -1;

int pqVal[MAX];
int pqPriority[MAX];



int isEmpty(){
    return idx == -1;
}

int isFull(){
    return idx == MAX - 1;
}

void enqueue(int data, int priority)
{
    if(!isFull()){
        
        idx++;
 
        pqVal[idx] = data;
        pqPriority[idx] = priority;
    }
}

int peek()
{
    int maxPriority = INT_MIN;
    int indexPos = -1;
 	int i;
    for (i = 0; i <= idx; i++) { 
        if (maxPriority == pqPriority[i] && indexPos > -1 && pqVal[indexPos] < pqVal[i]) 
        {
            maxPriority = pqPriority[i];
            indexPos = i;
        }
        
        else if (maxPriority < pqPriority[i]) {
            maxPriority = pqPriority[i];
            indexPos = i;
        }
    }
    
    return indexPos;
}

void dequeue()
{
    if(!isEmpty())
    {
        int indexPos = peek();
		int i;
        for (i = indexPos; i < idx; i++) {
            pqVal[i] = pqVal[i + 1];
            pqPriority[i] = pqPriority[i + 1];
        }
 
        idx--;
    }
}

void display(){
	int i;
    for ( i = 0; i <= idx; i++) {
        printf("(%d, %d)\n",pqVal[i], pqPriority[i]);
    } 
}

int main()
{
	int option;
	do
 {
        printf("\n****MAIN MENU****");
        printf("\n 1. Insert an element");
        printf("\n 2. Delete an element");
        printf("\n 3. Display the queue");
        printf("\n 4. EXIT");
        printf("\n Enter your option");
        scanf("%d",&option);

        switch(option)
        {

           case 1:
           		printf("\nenter value and priority");
           		int data, priority;
           		scanf("%d %d", &data,&priority);
				enqueue(data, priority);
            	break;

			case 2:
        
               dequeue();
           
               break;
           case 3:
				display();
               break;

          
        }
    
    }while(option !=4);
    return 0;
     
}
