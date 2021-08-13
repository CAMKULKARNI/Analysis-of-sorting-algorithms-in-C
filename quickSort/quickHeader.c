#include <stdio.h>
#include <stdlib.h>
#include "quickHeader.h"

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

long int parition(long int a[], long int low, long int high)
{
    long int pivot = a[low], i = low + 1, j = high;

    while (i <= j)
    {
        while (i <= high && a[i] <= pivot)
        {
            i++;
            comparisons++;
        }
        while (j > low && a[j] >= pivot)
        {
            j--;
            comparisons++;
        }

        if (i < j)
        {
            long int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    if (j != low)
    {
        a[low] = a[j];
        a[j] = pivot;
    }

    return j;
}

long long int quickSort(long int a[], long int low, long int high)
{
    int pr;

    if (low < high)
    {
        pr = parition(a, low, high);
        quickSort(a, low, pr - 1);
        quickSort(a, pr + 1, high);
    }

    return comparisons;
}
