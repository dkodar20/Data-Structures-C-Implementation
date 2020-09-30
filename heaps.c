/* 
 * Rudr Tiwari
 * 111901011
 */
#include <stdio.h>
#include <limits.h>
#include <string.h>

int heapSize=0;

int parent(int i)
{	
	// Runs in O(1) time.
	return (i - 1)/2;
}

int left(int i)
{
	// Runs in O(1) time.
	return 2*i + 1;
}

int right(int i)
{
	// Runs in O(1) time.
	return 2*i + 2;
}

void swap(int *x, int *y)
{
	int temp = 0;
	temp = *x;
	*x = *y;
	*y = temp;
}

void minHeapify(int A[],int i)
{
	/*
	 * The minHeapify function maintains the heap property of the given array.
	 * In this algorithm it is assumed that the child heaps of the given index
	 * are already heapified.
	 * It runs in a time complexity of O(lg(n)).
	 */
	int l = left(i), r = right(i);
    int smallest;
	if (l <= heapSize && A[l] < A[i])
		smallest = l;
	else smallest = i;

	if (r <= heapSize && A[r] < A[smallest])
		smallest = A[r];

	if (smallest != i){
		swap(&A[smallest], &A[i]);
        minHeapify(A, smallest);
    }
}

int decreaseKey(int A[], int i, int newVal)
{
	/* Decrease the value of A[i] to newVal. Return 1 if the
	 * operation is successful and -1 otherwise.
	 * Time Complexity - O(lg(n)).
	 */
    if (newVal > A[i] || i > heapSize - 1){
    	printf("%d\n", -1);
        return -1;
    }
    A[i] = newVal;
    while (i >= 0 && A[i] < A[parent(i)]){
        swap(&A[i], &A[parent(i)]);
        i = parent(i);
    }
}

int insertKey(int A[], int key, int n)
{
	/* Insert the element key into the heap represented by A.
	 * Return 1 if the operation is successful and -1 otherwise.
	 * Time Complexity - O(lg(n)).
	 */

	if (heapSize < 0 || heapSize == n){
		printf("%d\n", -1);
		return -1;
	}

	heapSize += 1;
	A[heapSize - 1] = INT_MAX;
	decreaseKey(A, heapSize - 1, key);
	return 1;
}

int deleteKey(int A[], int i)
{
	/* Delete the element A[i] from the heap represented by A.
	 * Return 1 if the operation is successful and -1 otherwise.
	 * Time Complexity - O(n).
	 */
    if (heapSize < 1 || i > heapSize - 1){
        printf("%d\n", -1);
        return -1;
    }
    A[i] = A[heapSize - 1];
    heapSize -= 1;
    minHeapify(A, i);
    return 1;
}

int extractMin(int A[])
{
	/* Delete the root of the min heap represented by A. Return
	 * the deleted element if the operation is successful and -1
	 * otherwise. 
	 * Time Complexity - O(lg(n)).
	 */
    if (heapSize < 1){
    	printf("%d\n", -1);
        return -1;
    }
    int min = A[0];
    deleteKey(A, 0);
    printf("%d\n", min);
    return min;
}

int getMin(int A[])
{
	/* Get the root of the min heap represented by A. Return
	 * the element if the operation is successful and -1 otherwise.
	 * Time Complexity - Theta(1).
	 */
    if (heapSize < 1){
        printf("%d\n", -1);
        return -1;
    }

    printf("%d\n", A[0]);
    return A[0];
}

void print(int A[])
{
	/* Display the heap represented by A in the increasing order
	 * of their indices, one element per line.
	 */
    for (int i = 0; i < heapSize; i++) {
        printf("%d\n", A[i]);
    }
}


int main(int argc, char **argv)
{
	int n = 0;

	scanf("%d", &n);
	int A[n];

	// When feof(stdin) is zero it means that end of file is reached.
	while(feof(stdin) == 0){

		// We declare a character array to store the function given as input.
		char func[10];
		scanf("%s", func);

		if (strcmp(func, "INS") == 0){
			int key = 0;
			scanf("%d", &key);
			insertKey(A, key, n);
		}

		else if (strcmp(func, "DEL") == 0){
			int i = 0;
			scanf("%d", &i);
			deleteKey(A, i);
		}

		else if (strcmp(func, "EXT") == 0){
			extractMin(A);
		}

		else if (strcmp(func, "PRT") == 0){
			print(A);
		}

		else if (strcmp(func, "DEC") == 0){
			int i, newVal;
			scanf("%d %d", &i, &newVal);
			decreaseKey(A, i, newVal);
		}

		else if (strcmp(func, "MIN") == 0){
			getMin(A);
		}
	}
    
	return 0;
}
