/*
 * Rudr
 * 111901044
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Making of the Node structure.
struct Node{
	
	char data;
	struct Node *next;
	struct Node *prev;
};


void insert_b(char x, struct Node **head, int *size){
	/*
	 * The following function inserts a node at the starting of the list.
	 * It runs in O(1) time.
	 */
	struct Node *node = (struct Node *) malloc(sizeof(struct Node));

	node->data = x;
	node->next = *head;
	node->prev = NULL;

	// If the list is not empty then the prev element of the current head is changed
	// to the new node.
	if (*head != NULL)
		(*head)->prev = node;

	*head = node;
	// Incrementing the size.
	*size += 1; 
}


void insert_e(char x, struct Node **head, int *size){
	/*
	 * The function inserts a node at end of the list. Since we haven't maintained a
	 * tail pointer, we can run the function in O(N) time.
	 */
	struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
	struct Node *node = *head;

	if (node == NULL){
		new_node->prev = NULL;
		*head = new_node;
		*size += 1;
		return;
	}

	new_node->data = x;
	new_node->next = NULL;
	
	// Traversing through the list.
	while(node->next != NULL)
		node = node->next;

	node->next = new_node;
	new_node->prev = node;
	// Incrementing the size.
	*size += 1;

	return;
}


void insert_m(char x, char y, struct Node *prev_node, int *size){
	/*
	 * The function inserts a node after 1st occurence of an element equal to y.
	 * It runs in O(N) time.
	 */
	struct Node *new_node = (struct Node *) malloc(sizeof(struct Node *));
	new_node->data = x;

	// If the list is empty, print -1;
	if (prev_node == NULL){
		printf("%d\n", -1);
		return;
	}

 	// We find a node either whose next element is NULL or data stored in it is y.
	while (prev_node->data != y && prev_node->next != NULL){
		prev_node = prev_node->next;
	}

	if (prev_node->data == y){

		new_node->next = prev_node->next;
		new_node->prev = prev_node;
		prev_node->next = new_node;
		// Incrementing the size.
		*size += 1;
	}

	else printf("%d\n", -1);
}


void size_list(int size){

	// Function prints the size of the list.
	printf("%d\n", size);
}


int is_empty(int size){

	// Function prints 1 list is empty, 0 if it is not.
	return (size == 0);
}


void print_list(struct Node *node){

	// Prints the whole list.

	// Traversing through the list.
	while(node != NULL){
		printf("%c\n", node->data);
		node = node->next;
	}
}


void print_list_reverse(struct Node *node){

	// Prints the list in reverse order.
	while(node->next != NULL)
		node = node->next;

	// Traversing through the list.
	while(node != NULL){
		printf("%c\n", node->data);
		node = node->prev;
	}
}


struct Node *middle_element(struct Node *node, int size){

	// This function returns the pointer to the middle element of the list.
	// It comes handy in telling whether the list is a palindrome or not
	int mid = size/2;

	if (size == 0){
		printf("%d\n", -1);
		return NULL;
	}

	for (int i = 0; i < mid; ++i){
		node = node->next;
	}

//	printf("%d\n", node->data);
	return node;
}


void is_palindrome(struct Node *mid, int size){

	// The function prints 1 if the list elements form a palindrome and 0 otherwise.
	// We start from the middle element of the list as returned by the middle_element() 
	// function, and then compare whether each of the elements are equal by traversing
	// on both sides.
	int half = size/2;
	struct Node *mid1, *mid2;

	if (mid == NULL){
		printf("%d\n", 1);
		return;
	}

	if (size%2 == 0){
		mid2 = mid;
		mid1 = mid->prev;
	}

	else {
		mid2 = mid->next;
		mid1 = mid->prev;
	}

	for (int i = 0; i < half; i++){

		if (mid1->data == mid2->data){
			mid1 = mid1->prev;
			mid2 = mid2->next;
		}

		else {
			// If any of the element becomes unequal, print zero and return
			// from the function.
			printf("%d\n", 0);
			return;
		}
	}

	printf("%d\n", 1);
	return;
}


void search(struct Node *node, int y){

	// Finds the place of 1st node whose data is equal to y.
	int i = 1;
	// Traversing through the list.
	while(node != NULL && node->data != y){

		node = node->next;
		i += 1;
	}

	if (node == NULL){
		printf("%d\n", -1);
		return;
	}

	printf("%d\n", i);
}


int main(int argc, char **argv)
{
	// Declaring the head and size of the linked list.
	// Note that tail pointer is not used.
	struct Node *head = NULL;
	int size = 0;

	// The function takes input till end of file standard input is reached.
	while(feof(stdin) == 0){

		// Taking in the operation to be performed as input.
		char operation[6];
		scanf(" %s", operation);

		if (strcmp(operation, "INS-B") == 0){
			char x;
			scanf(" %c", &x);
			insert_b(x, &head, &size);
		}

		else if (strcmp(operation, "INS-E") == 0){
			char x;
			scanf(" %c", &x);
			insert_e(x, &head, &size);
		}

		else if (strcmp(operation, "INS-A") == 0){
			char x = 'a', y = 'a';
			scanf(" %c %c", &x, &y);
			insert_m(x, y, head, &size);
		}

		else if (strcmp(operation, "EMP") == 0){
			printf("%d\n", is_empty(size));
		}

		else if (strcmp(operation, "SZE") == 0){
			size_list(size);
		}

		else if (strcmp(operation, "PRT") == 0){
			print_list(head);
		}

		else if (strcmp(operation, "PRT-R") == 0){
			print_list_reverse(head);
		}

		else if (strcmp(operation, "PAL") == 0){
			is_palindrome(middle_element(head, size), size);
		}

		else if (strcmp(operation, "SRCH") == 0){
			char y;
			scanf(" %c", &y);
			search(head, y);
		}

		scanf("\n");
	}

	return 0;
}
