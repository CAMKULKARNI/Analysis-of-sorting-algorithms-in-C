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

long long int bubbleSort(long int a[], long int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int swapped = 0;
        for (int j = i; j < n; j++)
        {
            comparisons++;
            if (a[i] > a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                swapped = 1;
            }
        }
        if (!swapped)
            break;
    }

    return comparisons;
}