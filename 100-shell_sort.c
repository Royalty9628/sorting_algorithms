#include "sort.h"

/**
 * shell_sort - function that sorts an array of integers in ascending order
 * @array: Array of integers
 * @size: size of the array
 * Return: Void
 */

void shell_sort(int *array, size_t size)
{
	size_t i, j, space = 1;
	int swap;

	if (array == NULL || size < 2)
		return;

	while (space < size / 3)
		space = 3 * space + 1;

	while (space > 0)
	{
		for (i = space; i < size; i++)
		{
			swap = array[i];
			for (j = i; j >= space && array[j - space] > swap; j -= space)
			{
				array[j] = array[j - space];
			}
			array[j] = swap;
		}
		space = (space - 1) / 3;
		print_array(array, size);
	}
}
