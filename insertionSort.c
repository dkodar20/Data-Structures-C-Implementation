#include <stdio.h>
#include <stdlib.h>


void F1(int length, long long int *array);


void insertion_sort(int length, long long int *array);


void print_array(int length, long long int *array);


int main(int argc, char **argv)
{
	
	// Reading the length of array.
	int n;
	scanf("%d", &n);

	long long int arr[n];

	// Reading the values of array elements.
	for(int i = 0; i < n; i++)
		scanf("%lld", arr+i);

	// Sorting the array.
	insertion_sort(n, arr);

	// Printing the array.
	print_array(n, arr);

	return 0;
}


void F1(int length, long long int *array){

	/* 
	 * The function takes an array whose first n - 1 elements are sorted and 
	 * a random integer at nth position. On calling the function, places the 
	 * nth element at its correct place so as the whole array becomes sorted.
	 *
	 * Time Complexity - The function has just one loop which iterates over the
	 * 					 length of the array. Hence the time complextity is 
	 *					 given by O(length).
	 *
	 * Space - The function declares a long long int(8 bytes) and an int vari-
	 *		   -able(4 bytes), thus takes 12 bytes of extra space while program
	 *	   	   execution
	 */
	long long int key = *(array + length - 1);

	int i = length - 2;
	while(key < array[i] && i >= 0){
		*(array + i + 1) = *(array + i);
		i--; 
	}

	array[i+1] = key;

}


void insertion_sort(int length, long long int *array){

	/*
	* The function takes an array and its length as its arguments and sorts it.
	* 
	* Time Complexity - Time complexity of F1(i, array) is O(i) and thus the 
	* 					time complexity of this function is given by O(1) + O(2)
	* 					+ ...O(length) = O(length*(length+1)/2) = O(length ^ 2).
	*
	* Space - The function declares just one additional int variable(i) and thus
	* 		  occupies 4 bytes of extra space.
	*/
	for (int i = 1; i <= length; i++)
		F1(i, array);
}


void print_array(int length, long long int *array){

	/*
	 * The function takes the array length and the array as arguments and 
	 * prints the array.
	 */
	for(int i = 0; i < length; i++)
		printf("%lld\n", array[i]);
}