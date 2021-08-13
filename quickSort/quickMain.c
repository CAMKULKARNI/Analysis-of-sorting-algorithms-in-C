#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "quickHeader.h"

int main()
{
    FILE *quick_comparions, *quick_time;
    quick_comparions = fopen("Quick_Comparisons.txt", "w");
    quick_time = fopen("Quick_Time.txt", "w");
    for (long int n = 0; n < 1000001; n = n + 50000)
    {
        long int *a = initializeArray(n);

        clock_t start, end;
        start = clock();
        int comparisons = quickSort(a, 0, n - 1);
        end = clock();

        clock_t totalTime = end - start;

        fprintf(quick_comparions, "\n%d\t%lld", n, comparisons);
        fprintf(quick_time, "\n%d\t%d", n, totalTime);
    }
    fclose(quick_comparions);
    fclose(quick_time);
}
