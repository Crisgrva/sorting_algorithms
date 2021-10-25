#include "sort.h"
/**
 * swap_array_sort - function to swap two integers
 * @a: int to swap with b
 * @b: int to swap with a
 * Return: nothing
 */
void swap_array_sort(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * quick_sort - function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * @array: array of integers
 * @size: size of the array
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;
	Sorting(array, 0, size - 1, size);
}

/**
 * Sorting - function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * @arr: array of integers
 * @signlow: Starting Index
 * @signhigh: Ending Index
 * @size: size of the array
 * Return: Nothing
 */
void Sorting(int arr[], int signlow, int signhigh, size_t size)
{
	int pi = 0;

	if (signlow < signhigh)
	{
		pi = partition(arr, signlow, signhigh, size);

		Sorting(arr, signlow, pi - 1, size);
		Sorting(arr, pi + 1, signhigh, size);
	}
}

/**
 * partition - function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * @arr: array of integers
 * @signlow: Starting Index
 * @signhigh: Ending Index
 * @size: size of the array
 * Return: Nothing
 */
int partition(int arr[], int signlow, int signhigh, size_t size)
{
	int pivot = arr[signhigh], i = (signlow - 1), j = 0;

	for (j = signlow; j <= signhigh - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap_array_sort(&arr[i], &arr[j]);
				print_array(arr, size);
			}
		}
	}
	if (i + 1 != signhigh)
	{
		swap_array_sort(&arr[i + 1], &arr[signhigh]);
		if (i != j)
			print_array(arr, size);
	}
	return (i + 1);
}
