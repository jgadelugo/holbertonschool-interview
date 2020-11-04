#include "sort.h"


/**
 * merge - merges two subwarrays
 * @arr: array
 * @l: left index
 * @m: middle
 * @r: right
 */
void merge(int *arr, int l, int m, int r)
{
	int i, j, k, n1 = m - l + 1, n2 = r - m, L[n1], R[n2];

	printf("Merging...\n[left]: ");
	for (i = 0; i < n1; i++)
	{
		L[i] = arr[l + i];
		if (i != n1 - 1)
			printf("%d, ", arr[l + i]);
		else
			printf("%d\n[right]: ", arr[l + i]);
	}
	for (j = 0; j < n2; j++)
	{
		R[j] = arr[m + 1 + j];
		if (j != n2 - 1)
			printf("%d, ", arr[m + 1 + j]);
		else
			printf("%d\n[Done]:", arr[m + 1 + j]);
	}
	i = j = k = 0;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		printf(" %d", arr[k]);
		k++;
	}
	printf("\n");
	for (; i < n1; i++, k++)
		arr[k] = L[i];
	for (; j < n2; j++, k++)
		arr[k] = R[j];
}

/**
 * mergeSort - merge sort an array
 * @arr: array to sort
 * @l: left index
 * @r: right index
 */
void mergeSort(int *arr, int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

/**
 * merge_sort - merge sort an array
 * @array: array to sort
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
	if (!array || !size || size == 1)
		return;

	mergeSort(array, 0, size - 1);
}
