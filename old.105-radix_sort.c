/* #include "sort.h"

**
 * radix_sort - sorts an array of integers in ascending
 * order.
 * 
 * @array: array of integers greater than or equal to 0
 * @size: size of input array
 *
void radix_sort(int *array, size_t size)
{
    
} */

#include <stdio.h>
#include <stdlib.h>
int max_val(int *arr, int size);

/**
 * count_sort - sorts input array `in_arr` of length `in_size`
 * using counting sort.
 * 
 * @in_arr: array of integers to be sorted
 * @in_size: length of array to be sorted
 * Return: sorted array
 */
int *count_sort(int *in_arr, int in_size)
{
    int i;
    int cnt_size = max_val(in_arr, in_size);
    int *cnt_arr = malloc(sizeof(int) * (cnt_size + 1));
    int *result = malloc(sizeof(int) * (in_size));

    printf("\n\nEmpty Count Array:\n");
    for (i = 0; i < cnt_size; i++)
    {
        cnt_arr[i] = 0;
        printf("%d ", cnt_arr[i]);
    }

    for (i = 0; i < in_size; i++)
        cnt_arr[in_arr[i]]++;

    printf("\n\nPopulated Count Array:\n");
    for (i = 0; i < cnt_size; i++)
        printf("%d ", cnt_arr[i]);

    for (i = 1; i < cnt_size; i++)
        cnt_arr[i] += cnt_arr[i - 1];

    printf("\n\nCumulative Count Array:\n");
    for (i = 0; i < cnt_size; i++)
        printf("%d ", cnt_arr[i]);

    printf("\n\n");
    for (i = in_size - 1; i >= 0; i--)
    {
        result[cnt_arr[in_arr[i]] - 1] = in_arr[i];
        printf("%d: %d\n", cnt_arr[in_arr[i] - 1], in_arr[i]);
        cnt_arr[in_arr[i]]--;
    }

    printf("\n\nRESULT???\n");
    for (i = 0; i < in_size; i++)
        printf("%d ", result[i]);
    printf("\n");

    return (result);
}

/**
 * max_val - returns the maximum value in an array of
 * integers
 * 
 * @arr: integer array to be searched
 * @size: length of array to be searched
 * Return: maximum integer value in the array
 */
int max_val(int *arr, int size)
{
    int i, max = arr[0];

    for (i = 1; i < size; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    return (max);
}

int main(void)
{
    int i;
    int arr[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    int *res;

    printf("Before Sort:\n");
    for (i = 0; i < 10; i++)
        printf("%d ", arr[i]);

    res = count_sort(arr, 10);

    printf("\n\nAfter Sort:\n");
    for (i = 0; i < 10; i++)
        printf("%d ", res[i]);
    printf("\n");
}
