#include <stdio.h>
#include <stdlib.h>

struct CNode {
   int val;
   struct CNode* left;
   struct CNode* right;
};

struct CNode* createNode(int x) {
   struct CNode* newNode = (struct CNode*)malloc(sizeof(struct CNode));
   newNode->val = x;
   newNode->left = NULL;
   newNode->right = NULL;
   return newNode;
}

void inOrderTraversal(struct CNode* root, int* elements, int* index) {
   if (root != NULL) {
      inOrderTraversal(root->left, elements, index);
      elements[(*index)++] = root->val;
      inOrderTraversal(root->right, elements, index);
   }
}

struct CNode* sortedArrayToBST(int* elements, int start, int end) {
   if (start > end) {
      return NULL;
   }

   int mid = (start + end) / 2;
   struct CNode* newNode = createNode(elements[mid]);

   newNode->left = sortedArrayToBST(elements, start, mid - 1);
   newNode->right = sortedArrayToBST(elements, mid + 1, end);

   return newNode;
}

void mergeBSTs(struct CNode* root1, struct CNode* root2) {

   int size1 = 0, size2 = 0;
   inOrderTraversal(root1, NULL, &size1);
   inOrderTraversal(root2, NULL, &size2);


   int* elements1 = (int*)malloc(size1 * sizeof(int));
   int* elements2 = (int*)malloc(size2 * sizeof(int));


   int index1 = 0, index2 = 0;


   inOrderTraversal(root1, elements1, &index1);
   inOrderTraversal(root2, elements2, &index2);


   int* mergedElements = (int*)malloc((size1 + size2) * sizeof(int));
   int index = 0;
   int i = 0, j = 0;

   while (i < size1 && j < size2) {
      if (elements1[i] < elements2[j]) {
         mergedElements[index++] = elements1[i++];
      } else {
         mergedElements[index++] = elements2[j++];
      }
   }

   while (i < size1) {
      mergedElements[index++] = elements1[i++];
   }

   while (j < size2) {
      mergedElements[index++] = elements2[j++];
   }


   struct CNode* mergedBST = sortedArrayToBST(mergedElements, 0, size1 + size2 - 1);


   printf("Merged BST:\n");
   printInOrder(mergedBST);


   free(elements1);
   free(elements2);
   free(mergedElements);
}

void printInOrder(struct CNode* mergedBST) {
   if (mergedBST != NULL) {
      printInOrder(mergedBST->left);
      printf("%d ", mergedBST->val);
      printInOrder(mergedBST->right);
   }
}

int main() {

   struct CNode* root1 = createNode(5);
   root1->left = createNode(3);
   root1->right = createNode(7);
   root1->left->left = createNode(2);
   root1->left->right = createNode(4);
   root1->right->left = createNode(6);
   root1->right->right = createNode(8);


   struct CNode* root2 = createNode(10);
   root2->left = createNode(9);
   root2->right = createNode(12);
   root2->left->left = createNode(11);
   root2->left->right = createNode(13);


   mergeBSTs(root1, root2);
	
printInOrder(mergedBST);
	   
   return 0;
}

