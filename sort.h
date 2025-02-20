#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structure Definition */

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Function Prototypes */

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void move_to_loc(listint_t *nodeToMove, listint_t *prevNode);
void partition(int *array, int low, int high, size_t size);
void move_to_head(listint_t *head, listint_t *nodeToMove);

void array_swap(int *array, int a, int b);
void list_swap(listint_t **list);

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);

void merge_sort(int *array, size_t size);
void merge(int *A, int *B, int left, int mid, int right);
void split(int *A, int *B, int left, int right);
void print_subarray(int *arr, int start, int end);

void heap_sort(int *array, size_t size);
void heapify(int *array, int i, int len, size_t size);
void swap(int *a, int *b);
int iRightChild(int i);
int iLeftChild(int i);
int iParent(int i);

int max_val(int *arr, int size);
void count_sort(int *in_arr, int in_size, int place);
void radix_sort(int *array, size_t size);

#endif
