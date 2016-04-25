/*
 * This lab is to represent a list of integers using a singly connected 
 * linked list by prompt the user of some some operations such as insertion, 
 * deletion, printing etc.
 *
 * by Sheng Wang
 */
#include <stdio.h>
#include <stdlib.h>

/* Typedef the struct node as name node. */
typedef struct node {
	int data;
	struct node *next;
} node;

/* Create a new node with given data. */
node *createNode(int data) {
	/* Dynamic allocate the memory for the node. */
	node *newNode = (node *)malloc(sizeof(node));
	newNode -> data = data;
	newNode -> next = NULL;
	return newNode;
}

/* Insert the node to the list in a non-decreasing order. */
void insertNode(node **head, node *newNode) {
	if (*head == NULL) {
		*head = newNode;
	}
	/* Compare the head data with the new node data. */
	else if ((*head) -> data >= newNode -> data) {
		/* Insert to front. */
		newNode -> next = *head;
		*head = newNode;
	}
	else {
		node *temp = *head;
		while (temp != NULL) {
			/* Insert to end. */
			if (temp -> next == NULL) {
				temp -> next = newNode;
				break;
			}
			else if (temp -> next -> data >= newNode -> data) {
				newNode -> next = temp -> next;
				temp -> next = newNode;
				break;
			}
			temp = temp -> next;
		}
	}
}	

/* Deletes all nodes in the linked list with that data. */
void deleteNode(node **head, int data) {
	node *temp = *head;
	node *prev = NULL;
	while (temp != NULL) {
		/* Find the node with the same data. */
		if (temp -> data == data) {
			if (prev == NULL) {
				*head = (*head) -> next;
				free(temp);
			}
			else {
				prev -> next = temp -> next;
				free(temp);
			}
		}
		else {
			prev = temp;
		}
		temp = temp -> next;
	}
}

/* Prints all the elements sequentially. */
void printList(node *head) {
	while (head != NULL) {
		printf("%d ", head -> data);
		head = head -> next;
	}
	printf("\n");
}

/* Deletes all nodes in that linked list */
void freeList(node *head) {
	node *temp;
	while (head != NULL) {
		temp = head;
		head = head -> next;
		free(temp);
	}
}


int main() {
	int x, data;
	node *head = NULL, *newNode;
	/* Constantly prompt the user to choose an option. */
	while (1) {
		printf("0--Exit the program\n");
     		printf("1--Insert a node\n");
       		printf("2--Delete a node\n");
       		printf("3--Print the list\n");
		printf("PLease enter among 0,1,2 or 3: ");
		scanf("%d",&x);
		switch(x) {
		/* Exit the program. */
		case 0:
			freeList(head);
			return 0;
		/* Create a new node with the data as the integer and insert this node in the linked list. */
		case 1: 
			printf("Enter an integer to insert: ");
			scanf("%d",&data);
			newNode = createNode(data);
			insertNode(&head, newNode);
			break;
		/* Delete all nodes in the linked list having the same data value as the input. */
		case 2:
			printf("Enter an integer to delete: ");
			scanf("%d",&data);
			deleteNode(&head, data);
			break;
		/* Print the entire linked list. */
		case 3: 
			printList(head);
			break;
		default:
			printf("Invalid input, please try again.\n");
		}
	}
	return 0;
}
