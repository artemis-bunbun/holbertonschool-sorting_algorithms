#include "sort.h"

/**
 * lomuto_partition - Lomuto partition scheme for quick sort
 * @array: The array being sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition (pivot is always array[high])
 * @size: Total size of the array (used for printing)
 *
 * Return: The final index of the pivot element
 */
static int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j, tmp;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				/* Swap array[i] and array[j] */
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}

	/* Place pivot in its correct sorted position */
	if (array[i + 1] != array[high])
	{
		tmp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = tmp;
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quick_sort_recursive - Recursive helper for quick sort
 * @array: The array being sorted
 * @low: Starting index of the current partition
 * @high: Ending index of the current partition
 * @size: Total size of the array
 */
static void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = lomuto_partition(array, low, high, size);
		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm (Lomuto partition scheme)
 * @array: The array to sort
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, (int)(size - 1), size);
}
