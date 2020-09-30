#include <stdio.h>
#include <stdlib.h>

void print_matrix(int rows, int cols, int *ptr);

void compute_transpose(int rows, int cols, int *ptr, int *trans_ptr);

void add_elements_to_matrix(int rows, int cols, int extra_rows, int extra_cols, int *ptr);

int compute_sum(int rows,int columns, int *ptr);

int main()
{
	// Declaration of p, q and the pointer to matrix
	int p, q, *ptr_to_matrix;

	// Reading values of p and q
	scanf("%d %d", &p, &q);

	// Check that p and q are positive
	if (p < 0 || q < 0)
	{
		printf("p and q should be positive.\n");
		return 0;
	}

	ptr_to_matrix = (int *) malloc(p * q * sizeof(int)); // memory allocation

	// p is the number of rows of matrix
	// q is the number of columns	
	// Reading elements of matrix
	for(int i = 0; i < p; i++)
		for(int j = 0; j < q; j++)
			scanf("%d", ptr_to_matrix + q*i + j);
	printf("\n");

	// Printing elements of matrix
	print_matrix(p, q, ptr_to_matrix);

	// Declaring pointer to the transpose matrix
	int *ptr_to_trans_matrix;

	ptr_to_trans_matrix = (int *) malloc(p * q * sizeof(int)); 

	compute_transpose(p, q, ptr_to_matrix, ptr_to_trans_matrix);

	// Printing the transpose matrix
	/* Number of rows of the transpose matrix is number
	of cols of transpose matrix and vice versa*/
	print_matrix(q, p, ptr_to_trans_matrix);
	free(ptr_to_trans_matrix);

	// Reading integers x and y
	int x = 0, y = 0;
	scanf("%d %d", &x, &y);

	// Check that x and y are positive.
	if (x < 0 || y < 0)
	{
		printf("x and y should be positive.\n");
		return 0;
	}

	/* Increasing the size of matrix so as to accomodate
	x more rows and y more columns */
	ptr_to_matrix = realloc(ptr_to_matrix, (p + x)*(q + y) * sizeof(int));

	// Takes input as extra elements of matrix
	add_elements_to_matrix(p, q, x, y, ptr_to_matrix);
	printf("\n");

	/* Prints the final matrix */
	print_matrix(p + x, q + y, ptr_to_matrix);

	// Printing the sum of elements of matrix
	printf("%d\n", compute_sum(p + x, q + y, ptr_to_matrix));

	free(ptr_to_matrix);

	return 0;
}


void print_matrix(int rows, int cols, int *ptr){
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
			printf("%d ", *(ptr + cols*i + j));
		printf("\n");
	}
	printf("\n");
}


void compute_transpose(int rows, int cols, int *ptr, int *trans_ptr){
	
	/* (i, j) element of original matrix becomes
	(j, i) element of transpose matrix */

	for(int i = 0; i < rows; i++)
		for(int j = 0; j < cols; j++)
			*(trans_ptr + rows*j + i) = *(ptr + cols*i + j);
}


void add_elements_to_matrix(int rows, int cols, int extra_rows, int extra_cols, int *ptr){
	/* Since the elements of the matrix are placed linearly in the allocated
	memory, to accomodate the extra spaces in each row, we move the elements
	in a manner that space for extra elemnts is created. */
	/* The below loop is takenin descending manner as taking it in
	ascending order will leave in loss of data of the elements coming 
	afterwards in loop*/
	for(int i = rows-1; i >= 0; i--)
		for(int j = cols-1; j >= 0; j--)
			*(ptr + (cols + extra_cols)*i + j) = *(ptr + cols*i + j);

	/* Reads the extra elements in each row and puts them to their 
	respective places. */
	for(int i = 0; i < rows; i++)
		for(int j = cols; j < cols + extra_cols; j++)
			scanf("%d", (ptr + i*(cols + extra_cols) + j));

	/* Finally reads the extra rows */
	for(int i = rows; i < rows + extra_rows; i++)
		for(int j = 0; j < cols + extra_cols; j++)
			scanf("%d", (ptr + i*(cols + extra_cols) + j));
}


int compute_sum(int rows, int cols, int *ptr){
	int sum = 0;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			sum += *(ptr + i*cols + j);
	return sum;
}
