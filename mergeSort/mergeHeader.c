#include <stdio.h>
#include <stdlib.h>
#include "mergeHeader.h"

long long int comparisons = 0;

long int *initializeArray(long int n)
{
	long int *a = (long int *)malloc(sizeof(long int) * n);

	for (long int i = 0; i < n; i++)
	{
		a[i] = rand();
	}

	return a;
}

void merge(long int a[], long int low, long int mid, long int high)
{
	long int i = low, j = mid + 1, k = 0, *b = (long int *)malloc(sizeof(long int) * (high - low + 1));
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			b[k++] = a[i];
			i++;
			comparisons++;
		}
		else
		{
			b[k++] = a[j];
			j++;
		}
	}
	while (i <= mid)
	{
		b[k++] = a[i];
		i++;
	}
	while (j <= high)
	{
		b[k++] = a[j];
		j++;
	}
	int l = low;
	for (i = 0; i < k; i++)
		a[l++] = b[i];
}

// long long int mergeSort(long int a[], long int low, long int high)
// {
// 	if (low < high)
// 	{
// 		int mid = (low + high) / 2;
// 		mergeSort(a, low, mid);
// 		mergeSort(a, mid + 1, high);
// 		merge(a, low, mid, high);
// 	}
// 	return comparisons;
// }

long long int mergeSort(long int a[], long int n)
{
	int mid = n / 2;
	mergeSort(a, 0, mid);
	mergeSort(a, mid + 1, n);
	merge(a, 0, mid, n);
	return comparisons;
}
