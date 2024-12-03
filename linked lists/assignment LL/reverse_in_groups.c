//WAP to Reverse a Linked List in groups of a given size. (Note: If a linked list
//consists of 12 elements and the size of the group is 3, then the first 3 elements need
//to be reversed, the next 3 elements need to be reversed, and so on.


#include <stdio.h>
#include <stdlib.h>

// Definition for a singly-linked list node
struct ListNode {
    int data;
    struct ListNode* next;
};

// Function to create a new node
struct ListNode* createNode(int data) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to reverse a linked list in groups of a given size
struct ListNode* reverseInGroups(struct ListNode* head, int groupSize) {
    struct ListNode* current = head;
    struct ListNode* prev = NULL;
    struct ListNode* next = NULL;
    int count = 0;

    // Count the number of nodes in the current group
    while (current != NULL && count < groupSize) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    // If there are more nodes to process, recursively reverse the next group
    if (next != NULL) {
        head->next = reverseInGroups(next, groupSize);
    }

    return prev;
}

// Function to print a linked list
void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    // Create a linked list
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->next = createNode(6);
    head->next->next->next->next->next->next = createNode(7);
    head->next->next->next->next->next->next->next = createNode(8);
//    head->next->next->next->next->next->next->next->next = createNode(9);

    int groupSize = 4;

    printf("Original Linked List:\n");
    printList(head);

    // Reverse the linked list in groups
    head = reverseInGroups(head, groupSize);

    printf("\nLinked List after reversing in groups of %d:\n", groupSize);
    printList(head);

    return 0;
}

