/* 
1.To count number of leaf nodes in the tree.
2.To count number of non-leaf nodes in the tree.
3. To find number of nodes in the tree.
4. To find sum of all nodes of the tree.
5. To print depth of the tree.
6. To find nodes which are at maximum depth in the tree?
7. To print all the elements of kth level in single line.
8. To find the common ancestor and print the paths.
9.To check whether a tree is a binary search tree or not. */


#include<stdio.h>
#include<malloc.h>

struct node{
	int data;
	struct node * left;
	struct node  *right;
};

struct node * tree=NULL;
struct node *insertElement(struct node *);
int count_leaf(struct node *);
int count_nonleaf(struct node *);
int totalNodes(struct node *);
int sum(struct node* );
int findDepth(struct node* );
void findNodesAtMaxDepth(struct node*, int , int); 
void printKthLevel(struct node*, int );
void ancestor(struct node *);
int isBST(struct  node* );

int main()
{
	int option, val;
	struct node *ptr;
	
	printf("\n ******MAIN MENU******* \n");
	printf("\n 1. Insert Element");
	printf("\n 2. count no of leaf nodes");
	printf("\n 3. count non leaf nodes");
	printf("\n 4. count total no of nodes");
	printf("\n 5. sum of all nodes");
	printf("\n 6. Find depth");
	printf("\n 7. find nodes present at maximum depth");
	printf("\n 8. print nodes at kth level");
	printf("\n 9. find common ancestor");
	printf("\n 10. Check if the tree is a BST");
	printf("\n 11. Exit");
	
	do
	{
		printf("\n\n Enter your option : ");
		scanf("%d", &option);
		
		switch(option)
		{
			case 1:
				printf("\n Enter the value of the new node : ");
				scanf("%d", &val);
				tree = insertElement(tree, val);
				break;
			case 2:
				printf("\n The no of leaf nodes in the tree are : %d \n",count_leaf(tree));
				break;
			case 3:
				printf("\n The no of non leaf nodes in the tree are : %d \n",count_nonleaf(tree));
				break;
			case 4:
				printf("\n no of nodes in the tree are : %d \n",totalNodes(tree));
				break;
			case 5:
				printf("\n Sum of all elements of tree :%d",sum(tree));
				break;
			case 6:
				printf("\n depth of the tree is is : %d",findDepth(tree));
				break;
			case 7:
				printf("\n elements at max depth: ");
				findNodesAtMaxDepth(struct node* tree, 1, findDepth(tree))
				break;
			case 8:
				printf("\n Enter the level : ");
				scanf("%d", &val);
				printf("\n nodes at kth level:");
				void printKthLevel(tree, val);
				break;
			case 9:
				printf("\n common ancestor of: ") 			
				ancestor(tree);
				break;
			case 10:
				val = isBST(tree);
				if(val =1)
					printf("\n yes the tree is a BST");
				if(val =0)
					printf("\n no the tree is not a BST");
				break;
		}
	}while(option!=11);
	getch();
	return 0;
}

struct node *insertElement(struct node *tree)
{	
	printf("\nenter data of the new node");
	scanf("%d",&val);
	
	struct node *ptr, *nodeptr, *parentptr;
	ptr = (struct node*)malloc(sizeof(struct node));
	ptr->data = val;
	ptr->left = NULL;
	ptr->right = NULL;
	if(tree==NULL)
	{
			tree=ptr;
			tree->left=NULL;
			tree->right=NULL;
	}
	else
	{
			parentptr=NULL;
			nodeptr=tree;
			while(nodeptr!=NULL)
	{
				parentptr=nodeptr;
				if(val<nodeptr->data)
					nodeptr=nodeptr->left;
				else
					nodeptr = nodeptr->right;
	}
			if(val<parentptr->data)
				parentpt->left = ptr;
			else
				parentptr->right = ptr;
	}
	return tree;
}


int count_leaf(struct node * tree){

	if(tree==NULL)
		return 0;
	else if((tree->left==NULL) && (tree->right==NULL))
		return 1;
	else
		return (count_leaf(tree->left) +
		count_leaf(tree->right));	

}


int count_nonleaf(struct node *tree)
{
	if( (tree==NULL) || ((tree->left==NULL) && (tree->right==NULL)))
			return 0;
	else
			return (count_nonleaf(tree->left)
			+ count_nonleaf(tree->right) + 1);
}


int totalNodes(struct node *tree)
{
	if(tree==NULL)
			return 0;
	else
			return(totalNodes(tree->left) + totalNodes(tree->right) + 1);
}


int sum(struct node* tree) 
{
    if (tree == NULL) {
        return 0;
    }

    int leftSum = sum(tree->left);
    int rightSum = sum(tree->right);
   
    return tree->data + leftSum + rightSum;
}


int findDepth(struct node* root){
    if (root == NULL) {
        return 0;
    }

    int leftDepth = findDepth(root->left);
    int rightDepth = findDepth(root->right);

    return (leftDepth > rightDepth) ? (leftDepth + 1) : (rightDepth + 1);
}



// Structure to store a node and its depth
struct NodeDepth {
    struct node* node;
    int depth;
};

// Function to find nodes at the maximum depth in the tree
void findNodesAtMaxDepth(struct node* tree, int currentDepth, int targetDepth) {
    if (tree == NULL) {
        return;
    }

    // If the current depth is equal to the target depth, print the node
    if (currentDepth == targetDepth) {
        printf("Node at depth %d: %d\n", currentDepth, tree->data);
        return;
    }

    // Recursively find nodes at the maximum depth in left and right subtrees
    findNodesAtMaxDepth(tree->left, currentDepth + 1, targetDepth);
    findNodesAtMaxDepth(tree->right, currentDepth + 1, targetDepth);
}



void printKthLevel(struct node* tree, int k) {
    if (tree == NULL || k < 1) {
        return;
    }

    // If k is 1, print the current node's data
    if (k == 1) {
        printf("%d ", tree->data);
    } else {
        // Recursively print elements at the kth level in left and right subtrees
        printKthLevel(tree->left, k - 1);
        printKthLevel(tree->right, k - 1);
    }
}



void ancestor(struct node *temp)
{
    int a, b, anc = 0;
    count = 0;
 
    printf("enter two node values to find common ancestor\n");
    scanf("%d", &a);
    scanf("%d", &b);
    count = search(tree, a, b);
    if (count  == 2)
    {
        while (temp->value != a && temp->value != b)
        {
            if ((temp->value > a)&&(temp->value > b))
            { 
                anc = temp->value;
                temp = temp->l;
            }
            else if ((temp->value < a)&&(temp->value < b))
            {
                anc = temp->value;
                temp = temp->r;
            }
            else if ((temp->value > a)&&(temp->value < b))
            {
                anc = temp->value;            
                printf("anc = %d\n", anc);
                break;
            }
            else if ((temp->value < a)&&(temp->value > b))
            {
                anc = temp->value;
                temp = temp->r;    
            }
            else
            {
                printf("common ancestor = %d\n", anc);
                break;
            }
        }
    path(anc, a, b);
    }
    else
        printf("enter correct node values & do not enter root value\n");
}



int isBST(struct  node* root){
    static struct node *prev = NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}


