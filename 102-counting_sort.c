#include "sort.h"

/**
 * counting_sort -Sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: array to ba sorted
 * @size: size of array
 * Return: no return
 */

void counting_sort(int *array, size_t size)
{
	int i, tmp;
	size_t j;
	int *output = NULL, *count = NULL;

	if (array == NULL || size < 2)
		return;

	output = malloc((size + 1) * sizeof(int));
	if (output == NULL)
		return;

	tmp = array[0];
	for (j = 1; j < size; j++)
	{
		if (array[j] > tmp)
			tmp = array[j];
	}

	count = malloc((tmp + 1) * sizeof(int));
	if (count == NULL)
	{
		free(output);
		return;
	}

	for (j = 0; j < size; j++)
		count[array[j]]++;
	for (i = 1; i <= tmp; i++)
		count[i] += count[i - 1];
	print_array(count, tmp + 1);
	for (j = 0; j < size; j++)
	{
		output[count[array[j]] - 1] = array[j];
		count[array[j]]--;
	}
	for (j =0; j < size; j++)
		array[j] = output[j];
	free(count);
	free(output);
}
