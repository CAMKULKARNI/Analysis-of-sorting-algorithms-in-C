#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "selectionHeader.h"

int main()
{
    FILE *selection_comparions, *selection_time;
    selection_comparions = fopen("Selection_Comparisons.txt", "w");
    selection_time = fopen("Selection_Time.txt", "w");
    for (long int n = 0; n < 1000001; n = n + 50000)
    {
        long int *a = initializeArray(n);

        clock_t start, end;
        start = clock();
        int comparisons = selectionSort(a, n);
        end = clock();

        clock_t totalTime = end - start;

        fprintf(selection_comparions, "\n%d\t%lld", n, comparisons);
        fprintf(selection_time, "\n%d\t%d", n, totalTime);
        printf("%d\n", n);
    }
    fclose(selection_comparions);
    fclose(selection_time);
}
