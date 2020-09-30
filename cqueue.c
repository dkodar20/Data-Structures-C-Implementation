#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The queue structure.
typedef struct queue1
{
	int *array;
	int front;
	int rear;
	unsigned int capacity;

} Queue;

Queue* create_empty_queue(int cap){

	// This function creates an instance of an empty queue structure.
	// It returns the pointer to the queue structure.
	Queue *que;
	que = (Queue *) malloc(sizeof(Queue));
	que->front = -1;
	que->rear = 0;
	que->capacity = cap;
	int *arr = (int *) malloc(sizeof(que));
	que->array = arr;

	return que;
}


int size(Queue *que){

	/*
	 * The following function returns the number of elements in the queue.
	 * The function runs in O(1) time complexity
	 */

	// The front element initially points to -1 and the queue is empty that time
	if (que->front == -1)	return 0;
	return (que->capacity - que->front + que->rear) % que->capacity;
}


int isEmpty(Queue *que){

	// Returns zero if queue is empty, one if it is not.
	// Runs in O(1) time complexity.
	return size(que) == 0;
}

int isFull(Queue *que){

	// Returns zero if queue is full, one if it is not.
	// Runs in O(1) time complexity.
	// We declare the queue to be full when it has one less than the maximum number
	// of elements in the array.
	return size(que) == que->capacity - 1;
}


int peakFront(Queue *que){

	// Returns the front element in the queue and returns -1 if it is empty.
	// Time Complexity - O(1).
	if (!isEmpty(que))
		return que->array[que->front];
	return -1;
}


int enqueue(Queue *que, int element){
	
	// Adds an element at the end of the queue. 
	// Returns and prints -1 if the queue is full.
	// Time coplexity - O(1).
	if (!isFull(que)){

		if (que->front == -1)	que->front += 1; 
		que->array[que->rear] = element;
		que->rear = (que->rear + 1) % que->capacity;
		return element;
	}

	printf("%d\n", -1);
	return -1;
}


int dequeue(Queue *que){

	// Removes the front element from the queue and returns its value.
	// Returns -1 if the queue is empty.
	// Time Complexity - O(1).
	if (!isEmpty(que)){

		int front_element = que->array[que->front];
		que->front = (que->front + 1) % que->capacity;
		return front_element;
	}

	return -1;
}


void print(Queue *que){

	// Prints the queue starting from the element in front upto to the ending
	// of the queue.
	for (int i = 0; i < size(que); i++){
		int index = (que->capacity + i + que->front) % que->capacity;
		printf("%d\n", que->array[index]);
	}
}

int main(int argc, char **argv)
{
	int n = 0;

	scanf("%d", &n);

	// Declaring the pointer to the queue.
	Queue *queue;

	// Creating an empty stack that is pointed to by the above declared pointer.
	queue = create_empty_queue(n);

	// Input continues till end of file is reached.
	while(feof(stdin) == 0){

		char operation[10];
		scanf("%s", operation);

		if (strcmp(operation, "ENQ") == 0){
			int x = 0;
			scanf("%d", &x);
			enqueue(queue, x);
		}

		else if (strcmp(operation, "DEQ") == 0){
			printf("%d\n", dequeue(queue));
		}

		else if (strcmp(operation, "FRN") == 0){
			printf("%d\n", peakFront(queue));
		}

		else if (strcmp(operation, "PRT") == 0){
			print(queue);
		}

		else if (strcmp(operation, "SZE") == 0){
			printf("%d\n", size(queue));
		}

		else if (strcmp(operation, "EMP") == 0){
			printf("%d\n", isEmpty(queue));
		}

		else if (strcmp(operation, "FUL") == 0){
			printf("%d\n", isFull(queue));
		}

		else break;
	}

	return 0;
	
}
