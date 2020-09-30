/*
 * Rudr
 * 111901044
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Making of the Node structure.
struct Node{

	int data;
	struct Node *next;
};


void insert_b(int x, struct Node **head, struct Node **tail, int *size){
	/*
	 * The following function inserts a node at the starting of the list.
	 * It runs in O(1) time.
	 */
	struct Node *new_head = (struct Node *) malloc(sizeof(struct Node));
	new_head->data = x;
	new_head->next = (*head);

	// If the list is empty, on insertion the head becomes tail as well.
	if ((*head) == NULL)
		(*tail) = new_head;

	(*head) = new_head;

	// Size incrementation.
	*size += 1;
}


void insert_m(int x, int y, struct Node *prev_node, struct Node **tail , int *size){
	/*
	 * The function inserts a node after 1st occurence of an element equal to y.
	 * It runs in O(N) time.
	 */
	struct Node *new_node = (struct Node *) malloc(sizeof(struct Node *));
	new_node->data = x;

	// If the list is empty we print -1.
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
		prev_node->next = new_node;
		// Size incrementation.
		*size += 1;

		// If the new node is at the end of the list we point tail towards it.
		if (new_node->next == NULL)	*tail = new_node;
	}

	else printf("%d\n", -1);
}


void insert_e(int x, struct Node **head, struct Node **tail, int *size){
	/*
	 * The function inserts a node at end of the list. Since we have maintained a
	 * tail pointer, we can run the function in O(1) time.
	 */
	struct Node *new_tail = (struct Node *) malloc(sizeof(struct Node));
	new_tail->data = x;
	new_tail->next = NULL;
	
	// If the list is empty, the tail becomes head as well.
	if (*tail == NULL){
		*head = new_tail;
		*tail = new_tail;
	}

	else {
		(*tail)->next = new_tail;
		*tail = new_tail;
	}

	// Size incrementation.
	*size += 1;
}


void delete(int y, struct Node **head, struct Node **tail, int *size){

	/*
	 * The function deletes the 1st node whose data is equal to y.
	 * It runs in O(N) time.
	 */
	struct Node *temp = *head, *temp_prev;

	// If y is equal to data in head node itself then it is deleted here. 
	if (temp != NULL && temp->data == y){
		*head = temp->next;

		// If there is only one element in the list then tail also becomes NULL. 
		if (temp->next == NULL)	*tail = temp->next;
		free(temp);

		// Size incrementation.
		*size -= 1;
		return;
	} 

	// Else we find the node with data y.
	while(temp != NULL && temp->data != y){
		temp_prev = temp;
		temp = temp->next;
	}

	// If no such node is found, print -1.
	if (temp == NULL){

		printf("%d\n", -1);
		return;
	}

	temp_prev->next = temp->next;

	free(temp);

	// If the deleted node was the tail of list, we need to change the tail pointer.
	if (temp_prev->next == NULL)	*tail = temp_prev;

	// Size incrementation.
	*size -= 1;
}

void middle_element(struct Node *node, int size){

	// The following function prints the center element of the list.
	// Runs in O(N) time.
	int mid = size/2;

	if (size == 0){
		printf("%d\n", -1);
		return;
	}

	// Traversing through the list.
	for (int i = 0; i < mid; ++i){
		node = node->next;
	}

	printf("%d\n", node->data);
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


int is_empty(int size){

	// Function prints 1 list is empty, 0 if it is not.
	return (size == 0);
}


void size_list(int size){

	// Function prints the size of the list.
	printf("%d\n", size);
}


void print_list(struct Node *node){

	// Prints the whole list.

	// Traversing through the list.
	while(node != NULL){
		printf("%d\n", node->data);
		node = node->next;
	}
}

int main(int argc, char **argv)
{
	struct Node *head = NULL;
	struct Node *tail = NULL;
	int size = 0;

	// The function takes input till end of file standard input is reached.
	while(feof(stdin) == 0){

		// Taking in the operation to be performed as input.
		char operation[10];
		scanf("%s", operation);

		if (strcmp(operation, "INS-B") == 0){
			int x = 0;
			scanf("%d", &x);
			insert_b(x, &head, &tail, &size);
		}

		else if (strcmp(operation, "INS-E") == 0){
			int x = 0;
			scanf("%d", &x);
			insert_e(x, &head, &tail, &size);
		}

		else if (strcmp(operation, "INS-A") == 0){
			int x = 0, y = 0;
			scanf("%d %d", &x, &y);
			insert_m(x, y, head, &tail, &size);
		}

		else if (strcmp(operation, "DEL") == 0){
			int y = 0;
			scanf("%d", &y);
			delete(y, &head, &tail, &size);
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

		else if (strcmp(operation, "MID") == 0){
			middle_element(head, size);
		}

		else if (strcmp(operation, "SRCH") == 0){
			int y = 0;
			scanf("%d", &y);
			search(head, y);
		}

		else continue;
	}

	return 0;
}
