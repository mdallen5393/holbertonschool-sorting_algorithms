#include "sort.h"

/**
 * radix_sort - sorts an array of integers in ascending
 * order.
 *
 * @array: array of integers greater than or equal to 0
 * @size: size of input array
 */
void radix_sort(int *array, size_t size)
{
	int max = max_val(array, size);
	int place;

	for (place = 1; max / place > 0; place *= 10)
	{
		count_sort(array, size, place);
		print_array(array, size);
	}
}



/**
 * count_sort - sorts input array `in_arr` of length `in_size`
 * using counting sort.
 *
 * @in_arr: array of integers to be sorted
 * @in_size: length of array to be sorted
 * @place: significant digit to sort by
 * Return: sorted array
 */
void count_sort(int *in_arr, int in_size, int place)
{
	int *result = malloc(sizeof(int) * (in_size + 1));
	int *count;
	int max = (in_arr[0] / place) % 10;
	int i;

	for (i = 1; i < in_size; i++)
	{
		if (((in_arr[i] / place) % 10) > max)
			max = in_arr[i];
	}
	count = malloc(sizeof(int) * (max + 1));

	for (i = 0; i < max; i++)
		count[i] = 0;

	for (i = 0; i < in_size; i++)
		count[(in_arr[i] / place) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = in_size - 1; i >= 0; i--)
	{
		result[count[(in_arr[i] / place) % 10] - 1] = in_arr[i];
		count[(in_arr[i] / place) % 10]--;
	}

	for (i = 0; i < in_size; i++)
		in_arr[i] = result[i];

	free(result);
	free(count);
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
