#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mergeHeader.h"

int main()
{
    FILE *merge_comparions, *merge_time;
    merge_comparions = fopen("Merge_Comparisons.txt", "w");
    merge_time = fopen("Merge_Time.txt", "w");
    for (long int n = 0; n < 1000001; n = n + 50000)
    {
        long int *a = initializeArray(n);

        clock_t start, end;
        start = clock();
        int comparisons = mergeSort(a, 0, n - 1);
        end = clock();

        clock_t totalTime = end - start;

        fprintf(merge_comparions, "\n%d\t%lld", n, comparisons);
        fprintf(merge_time, "\n%d\t%d", n, totalTime);
    }
    fclose(merge_comparions);
    fclose(merge_time);
}
