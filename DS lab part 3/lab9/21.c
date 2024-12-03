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


int isIdentical(struct CNode* root1, struct CNode* root2) {
   if (root1 == NULL && root2 == NULL) {
       
       return 1;
   }
   else if (root1 == NULL || root2 == NULL) {
       
       return 0;
   }
   else if (root1->val != root2->val) {
        return 0;
   }
   else {
       return isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right);
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

   struct CNode* root2 = createNode(5);
   root2->left = createNode(3);
   root2->right = createNode(7);
   root2->left->left = createNode(2);
   root2->left->right = createNode(4);
   root2->right->left = createNode(6);
   root2->right->right = createNode(8);


   if (isIdentical(root1, root2)) {
       printf("The two BSTs are identical\n");
   }
   else {
       printf("The two BSTs are not identical\n");
   }

   return 0;
}

