//7.5_1 Implement stack using queue and vice versa.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Implementing Queue using Linked List.

struct QueueNode {
    int val;
    struct QueueNode *next;
};

struct Queue{
    int size;
    struct QueueNode *front;
    struct QueueNode *tail;
};

void push(struct Queue *queue, int new_val) {
    if (queue == NULL) return;

    struct QueueNode *new_node = (struct QueueNode *)malloc(sizeof(struct QueueNode));

    new_node->val = new_val;
    new_node->next = NULL;

    if (queue->tail != NULL) {
        queue->tail->next = new_node;
    }

    queue->tail = new_node;

    if (queue->front == NULL) {
        queue->front = new_node;
        queue->size = 1;
    }
    else{
        queue->size++;
    }
}


void pop(struct Queue *queue) {
	
    if (queue == NULL || queue->front == NULL) 
		return;
		
    struct QueueNode *tmp = queue->front;
    
    queue->front = queue->front->next;
    
    free(tmp);
    queue->size--;
    
	if (queue->front == NULL) {
        queue->tail = NULL;
        queue->size = 0;
    }
}

int size(struct Queue *queue) {
    if (queue == NULL) {
        return 0;
    }
    else {
        return queue->size;
    }
}

bool isEmpty(struct Queue *queue) {
    if (queue == NULL) {
        return true;
    }
    else {
        return (queue->size == 0) ? true : false;
    }
}

//Implementing Stack using Queues.

typedef struct {
    struct Queue queue;
} Stack;

//Creates a stack
void stackCreate(Stack *stack, int maxSize) {
    if (stack == NULL) 
		return;
    
    stack->queue.front = stack->queue.tail = 0;
    stack->queue.size = 0;
}

//Push element x onto stack
void stackPush(Stack *stack, int element) {
    if (stack == NULL) 
		return;

    push(&stack->queue, element);
}

//Removes the element on top of the stack
void stackPop(Stack *stack) {
    if (stack == NULL) 
		return;

    int originalSize = size(&stack->queue);
    int i;
    for (i = 0; i < originalSize - 1; i++) {
        if (stack->queue.front == NULL) {
            return;
        }
        
		int tmp = stack->queue.front->val;
        pop(&stack->queue);
        push(&stack->queue, tmp);
    }

    pop(&stack->queue);
}


void stackdisplay(Stack *stack) {
    if (stack == NULL) 
		return;
	int originalSize = size(&stack->queue);
    int i;
    for (i = 0; i < originalSize - 1; i++){
        if (stack->queue.front == NULL) {
            int tmp = stack->queue.front->val;
            printf("\t %d",tmp);
			queue->front = queue->front->next;
        }
    }
}

//peek in stack
int stackTop(Stack *stack) {
    if (stack == NULL || stack->queue.tail == NULL) {
        return 0;
    }
    else {
        return stack->queue.tail->val;
    }
}

int main() {

    Stack s;
    int maxSize = 5;
    stackCreate(&s, maxSize);
    int val, option;
    do
    {
        printf("\n *****MAIN MENU*****");
        printf("\n 1. PUSH");
        printf("\n 2. POP");
        printf("\n 3. PEEK");
        printf("\n 4. DISPLAY");
        printf("\n 5. EXIT");
        printf("\n Enter your option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("\n Enter the number to be pushed on stack: ");
            scanf("%d", &val);
            stackPush(&s,val);
            break;

        case 2:
            stackPush(&s, 1);
            break;

        case 3:
            val = stackTop(&s);
            if (val != -1)
                printf("\n The value at the top of stack is: %d", val);
            else
                printf("\n STACK IS EMPTY");
            break;
        }
        case 4:
            stackdisplay(&s);
            break;

    } while (option != 5);
    return 0;
}
