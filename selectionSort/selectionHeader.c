#include <stdio.h>
#include <stdlib.h>

long long int comparisons = 0;

unsigned long int *initializeArray(long int n)
{
    long int *a = (long int *)malloc(sizeof(long int) * n);

    for (long int i = 0; i < n; i++)
    {
        a[i] = rand();
    }

    return a;
}

long long int selectionSort(long int a[], long int n)
{
    for (long int i = 0; i < n - 1; i++)
    {
        long int min_index = i;
        for (long int j = i + 1; j < n; j++)
        {
            comparisons++;
            if (a[min_index] > a[j])
            {
                min_index = j;
            }
        }

        if (min_index != i)
        {
            long int temp = a[min_index];
            a[min_index] = a[i];
            a[i] = temp;
        }
    }
    return comparisons;
}