#include "sort.h"

/**
 * radix_lsd - sort an array using radix sort lsd
 * @array: array to sort
 * @size: size of array
 * @div: divisor
 * @minNum: smallest number in list
 */
void radix_lsd(int *array, int size, int div, int minNum)
{
	int i;
	int bucket[10] = {0}, bucketIDX;
	int *output;

	output = malloc(sizeof(int) * size);
	if (!output)
		return;
	for (i = 0; i < size; i++)
		bucket[(array[i] - minNum) / div % 10]++;

	for (i = 1; i < 10; i++)
		bucket[i] += bucket[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		bucketIDX = (array[i] - minNum) / div % 10;
		output[--bucket[bucketIDX]] = array[i];
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(output);
}

/**
 * radix_sort - sort an array using radix sort
 * @array: array to sort
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	size_t i;
	int maxNum, minNum;

	if (!array || !size || size <= 1)
		return;

	maxNum = array[0];
	minNum = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > maxNum)
			maxNum = array[i];
		if (array[i] < minNum)
			minNum = array[i];
	}
	for (i = 1; (maxNum - minNum) / i > 0; i *= 10)
	{
		radix_lsd(array, size, i, minNum);
		print_array(array, size);
	}
}
