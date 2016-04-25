/*
 * This lab is to represent a set of numbers using a 
 * Binary Search Tree and to define some 
 * operations such as insertion, printing etc.
 *
 * by Sheng Wang
 */
#include <stdio.h>
#include <malloc.h>

/* Typedef the struct node as name node. */
typedef struct node{
	int value;
   	struct node *left;
   	struct node *right;
}node;

/* Create the node. */
node *createNode(int val){
	node *newnode = (node *)malloc(sizeof(node));
  	newnode->value = val;
   	newnode->left = NULL;
   	newnode->right = NULL;
   	return newnode;
}

/* Insert the node. */
void insertNode(node **root, node *temp){
	if (*root == NULL){
		*root = temp;
	} 
	else if (temp->value < (*root)->value){
		insertNode(&((*root)->left), temp);		
	} 
	else{
		insertNode(&((*root)->right), temp);	
	}
}

/* Print the inorder traversal of the tree. */
void inOrder(node *root){
	if (root == NULL){
		return;
	} 
	else{
		inOrder(root->left);
		printf("%d ", root->value);
		inOrder(root->right);
	}
}

/* Print the preorder traversal of the tree. */
void preOrder(node *root){
	if (root == NULL){
		return;
	} 
	else{
		printf("%d ", root->value);
		preOrder(root->left);
		preOrder(root->right);
	}
}

/* Calculate the size of the tree. */
int sizeOfTree(node *root){
	if (root == NULL){
		return 0;
	} 
	else{
		return 1 + sizeOfTree(root->left) + sizeOfTree(root->right);
	}
}

/* Calculate the height of the tree. */
int maxHeight(node *root){
	if (root == NULL){
		return 0;
	} 
	else{
		int lh = maxHeight(root->left);
		int rh = maxHeight(root->right);
		return 1 + (lh > rh ? lh : rh);
	}
}

/* Find the minimum value of the tree. */
int minValue(node *root){
	if (root == NULL){
		return 2147483647;
	} 
	else{
		int lm = minValue(root->left);
		int rm = minValue(root->right);
		int min = lm < rm ? lm : rm;
		return root->value < min ? root->value : min;
	}
}

int main(){
	int num, i, n, c;
	/* Prompt the user to input the size. */
	printf("Please enter the number of nodes in the tree: ");
	scanf("%d", &num);
	while (num < 1) {
		printf("Invalid, please make sure the number is greater than 0.\n");
		printf("Please enter the number of nodes in the tree: ");
		scanf("%d", &num);
	}
	node *root = NULL;
	for (i = 0; i < num; i++){
		/* Prompt the user to input the value. */
		printf("Please enter an integer: ");
		scanf("%d", &n);
		insertNode(&root, createNode(n));
	}
	/* Constantly ask the user to choose an option. */
	while (1){
		printf("0 -- Exit the program.\n");
      		printf("1 -- Print the inorder traversal of the Tree.\n");
       		printf("2 -- Print the preorder traversal of the Tree.\n");
       		printf("3 -- Print the size(no. of nodes) in the Tree.\n");
       		printf("4 -- Print the maximum height of the Tree.\n");
       		printf("5 -- Print the minimum value in the Tree.\n");
       		printf("Please choose an option among 0-5: ");
		scanf("%d", &c);
		switch(c){
		case 0:
			return 0;
		case 1:
			inOrder(root);
			printf("\n");
			break;
		case 2:
			preOrder(root);
			printf("\n");
			break;
		case 3:
			printf("There are %d nodes in tree.\n", sizeOfTree(root));
			break;
		case 4:
			printf("Maximum height of the tree is %d.\n", maxHeight(root));
			break;
		case 5:
			printf("Minimum value in the tree is %d.\n", minValue(root));
			break;
		default:
           		printf("Invalid choice. try again!!\n");
           		break;
       		}
		printf("\n");
	}
	return 0;
}
