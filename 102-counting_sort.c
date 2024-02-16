#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *c, *sorted, m, i;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	m = get_max(array, size);
	c = malloc(sizeof(int) * (m + 1));
	if (c == NULL)
	{
		free(sorted);
		return;
	}

	for (i = 0; i < (m + 1); i++)
		c[i] = 0;
	for (i = 0; i < (int)size; i++)
		c[array[i]] += 1;
	for (i = 0; i < (m + 1); i++)
		c[i] += c[i - 1];
	print_array(c, m + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted[c[array[i]] - 1] = array[i];
		c[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	free(sorted);
	free(c);
}