#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
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

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);

/*Bubble sort function*/
void bubble_sort(int *array, size_t size);

/*Insertion sort function*/
void insertion_sort_list(listint_t **list);

/*Selection sort function*/
void selection_sort(int *array, size_t size);

/*Quick sort function*/
void quick_sort(int *array, size_t size);
void swap(int *arr, int low, int high, size_t size);
int partition(int *arr, int low, int high, size_t size);

/*Shell sort function*/
void shell_sort(int *array, size_t size);

/*Cocktail sort function*/
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker);
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **list);

/*Counting sort function*/
void counting_sort(int *array, size_t size);
int find_maxnum(int *array, size_t size);
void fill_array(int *array_a, int *array_b, size_t size);

/*Merge sort function*/
void merge_sort(int *array, size_t size);
void topdownmergesort(int *array_a, int *array_b, int size);
void topdownsplitmerge(int *array_a, int *array_b, size_t size, size_t left, size_t right);
void topdownmerge(int *array_a, int *array_b, size_t size, size_t left, size_t mid, size_t right);
void copyarray(int *array_a, int ibegin, int iend, int *array_b);

/*Heap sort function*/
void swap_ints(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/*Radix sort function*/
int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/*Bitonic sort function*/
void swap_ints(int *a, int *b);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);

#endif
