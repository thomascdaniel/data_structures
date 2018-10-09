#include <stdio.h>
#define MAX_SIZE 100 //Maximum size of the array
 
 
/* Function declarations */
int maximum(int array[], int start, int len);
int minimum(int array[], int start, int len);
 
 
 
 
int main()
{
    int array[MAX_SIZE], N, max, min;
    int i;
 
    /* Reads size and elements of array */
    printf("Enter size of the array: ");
    scanf("%d", &N);
    printf("Enter %d elements in array: ", N);
    for(i=0; i<N; i++)
    {
        scanf("%d", &array[i]);
    }
 
    max = maximum(array, 0, N);
    min = minimum(array, 0, N);
 
    printf("Minimum element in array = %d\n", min);
    printf("Maximum element in array = %d\n", max);
 
    return 0;
}
 
 
 
/**
 * Recursive function to find maximum element in the given array.
 */
int maximum(int array[], int start, int len)
{
    int max;
 
    if(start >= len-2)
        return (array[start] > array[start + 1])
                    ? array[start]
                    : array[start + 1];
 
    max = maximum(array, start+1, len);
 
    return (array[start] > max)
                ? array[start]
                : max;
}
 
 
 
/**
 * Recursive function to find minimum element in the array.
 */
int minimum(int array[], int start, int len)
{
    int min;
 
    if(start >= len-2)
    {
        return (array[start] < array[start + 1])
                    ? array[start]
                    : array[start + 1];
    }
 
    min = minimum(array, start+1, len);
 
    return (array[start] < min)
                ? array[start]
                : min;
}
