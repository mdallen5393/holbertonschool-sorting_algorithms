#include "sort.h"

/**
 * merge_sort - sorts an array of integers in ascending order
 * using merge sort algorithm
 *
 * @array: array of integers to sort
 * @size: size of array to be sorted
 */
void merge_sort(int *array, size_t size)
{
	int len = (int)size, i;
	int *A = array, *B;

	/* Make a copy of input array A into array B */
	B = malloc(sizeof(int) * len);
	for (i = 0; i < len; i++)
		B[i] = A[i];

	split(B, A, 0, len);
	free(B);
}

/**
 * split - recursively splits an array into trivially sorted, single-member
 * subarrays.
 *
 * @A: first array
 * @B: temporary array
 * @left: left index of subarray
 * @right: right index of subarray
 */
void split(int *A, int *B, int left, int right)
{
	int mid;

	if (right - left <= 1)
		return;

	mid = (left + right) / 2;

	/* recursively split */
	split(B, A, left, mid);
	split(B, A, mid, right);

	/* merge back together */
	merge(A, B, left, mid, right);

	printf("Merging...\n[left]: ");
	print_subarray(A, left, mid);
	printf("[right]: ");
	print_subarray(A, mid, right);
	printf("[Done]: ");
	print_subarray(B, left, right);
}

/**
 * merge - merges two sorted arrays
 *
 * @A: first array to merge
 * @B: second array to merge
 * @left: start of first subarray
 * @mid: start of right subarray
 * @right: end of array
 */
void merge(int *A, int *B, int left, int mid, int right)
{
	int i, aPos, bPos;

	aPos = left;
	bPos = mid;

	for (i = left; i < right; i++)
	{
		if (aPos < mid && (bPos >= right || A[aPos] <= A[bPos]))
		{
			B[i] = A[aPos];
			aPos++;
		}
		else
		{
			B[i] = A[bPos];
			bPos++;
		}
	}
}

/**
 * print_subarray - prints a subarray given start and end
 *
 * @arr: array containing subarray to print
 * @start: first index to print
 * @end: index to print to
 */
void print_subarray(int *arr, int start, int end)
{
	int i;

	for (i = start; i < end - 1; i++)
		printf("%d, ", arr[i]);
	printf("%d\n", arr[i]);
}
