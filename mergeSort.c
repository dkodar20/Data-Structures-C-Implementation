#include <stdio.h>
#include <stdlib.h>


void merge_sort(int start, int end, long long int *array);


int F2(int i, int j, int l, int m, long long int *array);


void print_array(int length, long long int *array);


int main(int argc, char **argv)
{
    // Reading the length of the array.
    int n;
    scanf("%d", &n);

    long long int arr[n];

    // Reading the values of array elements.
    for(int i = 0; i < n; i++)
    scanf("%lld", arr+i);

    // Sorting the array.
    merge_sort(0, n-1, arr);

    // Printing the array.
    print_array(n, arr);

    return 0;
}


void merge_sort(int start, int end, long long int *array){
    /*
     * The funtion takes starting and ending index of the subpart of the array
     * which has to be sorted, and the array itself as arguments.
     *
     * Time Complexity - The time complexity of the function is given by solving
     *                   the recurrence relation T(n) = 2*T(n/2) + O(n) where n
     *                   is the length of the array, which comes out to be
     *                   T(n) = O(n*lg(n)).
     *
     * Space - Besides the space taken by F2, four extra int variables are
     *         declared with each function call. This can be avoided by using
     *         the values of the variables directly in arguments of F2, but
     *         decreases the readability of code.
     */
    if (start < end){
        int middle = (start + end)/2;

        merge_sort(start, middle, array);
        merge_sort(middle+1, end , array);

        int i = start, j = middle - start;
        int l = i+j+1, m = end - i-j-1;
        F2(i, j, l, m, array);
    }
}


int F2(int i, int j, int l, int m, long long int *array){

    /*
     * The function sorts the combination of subarrayss array[i...i+j] and
     * array[l...l+m] given that these subarrays are already sorted individ-
     * -ually.
     *
     * Time Complexity - Since each loop iterates itself either j or m number of
     *                   times, the time complexity of function is given by
     *                   O(j + m).
     *
     * Space - The function uses 3 extra variables and two more temporary
     *         arrays of size j+1 and m+1 and of type long long int. Hence
     *         extra space used will be 3*4 + 8* (j + 1 + m + 1) = 8*(j+m) + 28
     *         bytes.
     */

    // If m turns out to be negative after our evaluation in main, then that
    // part of array is already sorted.
    if (m < 0) return 0;

    int a = 0, b = 0, c = i;

    // Declaration of temporary arrays.
    long long int temp_arr_1[j+1], temp_arr_2[m+1];

    // Copying into temporary arrays.
    for (a = 0; a < j+1; a++)
        temp_arr_1[a] = array[i+a];

    for (b = 0; b < m+1; b++)
        temp_arr_2[b] = array[l+b];

    a = 0; b = 0;

    while (a < j + 1 && b < m + 1)
    {
        if (temp_arr_1[a] <= temp_arr_2[b]){
            array[c] = temp_arr_1[a];
            a++;
        }

        else{
            array[c] = temp_arr_2[b];
            b++;
        }
        c++;
        if (c == i+j+1) c = l;
    }

    // The left out elements of temp_arr_1 are placed in the original array.
    while (a < j+1){
        array[c] = temp_arr_1[a];
        a++;
        c++;
        if (c == i+j+1) c = l;
    }

    // The left out elements of temp_arr_2 are placed in the original array.
    while (b < m+1){
        array[c] = temp_arr_2[b];
        b++;
        c++;
        if (c == i+j+1) c = l;
    }

    return 0;

}


void print_array(int length, long long int *array){

    /*
     * The function takes the array length and the array as arguments and
     * prints the array.
     */

    for(int i = 0; i < length; i++)
    printf("%lld\n", array[i]);
}
