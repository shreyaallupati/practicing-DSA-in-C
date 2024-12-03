#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct QueueNode {
    int data;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
} Queue;

// Initialize an empty queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (!queue) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    queue->front = queue->rear = NULL;
    return queue;
}

// Check if the queue is empty
bool isEmpty(Queue* queue) {
    return queue->front == NULL;
}

// Enqueue an element into the queue
void enqueue(Queue* queue, int value) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    if (!newNode) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Dequeue an element from the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        fprintf(stderr, "Queue is empty\n");
        exit(EXIT_FAILURE);
    }

    QueueNode* temp = queue->front;
    int value = temp->data;

    queue->front = queue->front->next;
    free(temp);

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    return value;
}

// Implement a stack using two queues
typedef struct {
    Queue* q1;
    Queue* q2;
} Stack;

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (!stack) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    stack->q1 = createQueue();
    stack->q2 = createQueue();
    return stack;
}

// Push an element onto the stack
void push(Stack* stack, int value) {
    if (isEmpty(stack->q1)) {
        enqueue(stack->q1, value);
        while (!isEmpty(stack->q2)) {
            enqueue(stack->q1, dequeue(stack->q2));
        }
    } else {
        enqueue(stack->q2, value);
        while (!isEmpty(stack->q1)) {
            enqueue(stack->q2, dequeue(stack->q1));
        }
    }
}

// Pop the top element from the stack
int pop(Stack* stack) {
    if (!isEmpty(stack->q1)) {
        return dequeue(stack->q1);
    } else if (!isEmpty(stack->q2)) {
        return dequeue(stack->q2);
    } else {
        fprintf(stderr, "Stack is empty\n");
        exit(EXIT_FAILURE);
    }
}

int main() {
    Stack* stack = createStack();

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("Popped: %d\n", pop(stack));
    printf("Popped: %d\n", pop(stack));

    push(stack, 40);
    printf("Popped: %d\n", pop(stack));

    return 0;
}

