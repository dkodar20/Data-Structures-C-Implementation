#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// The stack structure.
typedef struct stack1{

	int *array;
	int top;
	unsigned int capacity;
} Stack;


Stack* create_empty_stack(int cap){

	// The function creates an instance of the stack and returns 
	// the pointer to the empty stack.
	Stack *stk;
	stk = (Stack *) malloc(sizeof(Stack));
	stk->top = -1;
	stk->capacity = cap;
	int *arr = (int *) malloc(sizeof(int));
	stk->array = arr;

	return stk;
}


int isFull(Stack *stk){

	// The function returns 1 if the stack is full and 0 if it is not.
	// Time Complexity - O(1)
	if (stk->top == stk->capacity-1)
		return 1;
	else return 0;
}


int isEmpty(Stack *stk){

	// The function returns 1 if the stack is empty and 0 if it is not.
	// Time Complexity - O(1)
	if (stk->top == -1)
		return 1;
	else return 0;
}


int peek(Stack *stk){

	// Returns the top element of the stack and -1 if the stack is empty.
	// Time Complexity - O(1)
	if (!isEmpty(stk))
		return stk->array[stk->top];
	else
		return -1;

}


int size(Stack *stk){

	// Retruns the number of elements in the stack.
	// Time Complexity - O(1)
	return stk->top + 1;
}


int pop(Stack *stk){

	// Removes the topmost element of the stack and returns its value.
	// Returns -1 if the stack is empty.
	// Time COmplexity - O(1)
	if (!isEmpty(stk)){

		stk->top -= 1;
		return stk->array[stk->top+1];
	}

	else return -1;
}


int push(Stack *stk, int element){

	// Adds an element on the top of the stack.
	// Prints and returns -1 if the stack is full.
	// Time COmplexity - O(1)
	if (!isFull(stk) && element >= 0){

		stk->top += 1;
		int top_index = stk->top;
		stk->array[top_index] = element;
		return element;
	}

	printf("%d\n", -1);
	return -1;
}


void print(Stack *stk){

	// Prints the elements of the stack from the topmost element 
	// upto the bottommost one.
	for (int i = size(stk) - 1; i >= 0; i--){
		printf("%d\n", stk->array[i]);
	}
}


int main(int argc, char **argv)
{
	int n = 0;

	scanf("%d", &n);

	// Declaration to a stack pointer.
	Stack *stack;

	// Creating an empty stack that is pointed to by the above declared pointer.
	stack = create_empty_stack(n);

	// Input continues till end of file is reached.
	while(feof(stdin) == 0){

		char operation[10];
		scanf("%s", operation);

		if (strcmp(operation, "PSH") == 0){
			int x = 0;
			scanf("%d", &x);
			push(stack, x);
		}

		else if (strcmp(operation, "POP") == 0){
			printf("%d\n", pop(stack));
		}

		else if (strcmp(operation, "TOP") == 0){
			printf("%d\n", peek(stack));
		}

		else if (strcmp(operation, "PRT") == 0){
			print(stack);
		}

		else if (strcmp(operation, "SZE") == 0){
			printf("%d\n", size(stack));
		}

		else if (strcmp(operation, "EMP") == 0){
			printf("%d\n", isEmpty(stack));
		}

		else if (strcmp(operation, "FUL") == 0){
			printf("%d\n", isFull(stack));
		}

		else break;
	}

	return 0;

}
