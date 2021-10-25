#include "sort.h"

/**
 * selection_sort - function that sorts an array of integers in
 * ascending order using the Selection sort algorithm
 * @array: array to evaluate
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, p = 0;

	if (!array || size <= 1)
		return;

	for (i = 0; i < (size - 1); i++, p = i)
	{
		for (j = (i + 1); j < size; j++)
			if (array[j] < array[p])
				p = j;
		if (p != i)
			swap_array(array, size, &array[p], &array[i]);
	}
}
/**
 * swap_array - function to swap two integers in array
 * @array: array to evaluate
 * @size: size of the array
 * @a: int to swap
 * @b: int to swap
 */
void swap_array(int *array, size_t size, int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	print_array(array, size);
}
