#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bubbleHeader.h"

int main()
{
    FILE *bubble_comparions, *bubble_time;
    bubble_comparions = fopen("Bubble_Comparisons.txt", "w");
    bubble_time = fopen("Bubble_Time.txt", "w");
    for (long int n = 0; n < 1000001; n = n + 50000)
    {
        long int *a = initializeArray(n);

        clock_t start, end;
        start = clock();
        int comparisons = bubbleSort(a, n);
        end = clock();

        clock_t totalTime = end - start;

        fprintf(bubble_comparions, "\n%d\t%lld", n, comparisons);
        fprintf(bubble_time, "\n%d\t%d", n, totalTime);
        printf("%d\n", n);
    }
    fclose(bubble_comparions);
    fclose(bubble_time);
}
