#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define N 10
#define a 0
#define b 99

int data[N];

void print_data(int p[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d\t", p[i]);
    }
    printf("\n");
}

int partition(int p[], int start, int end)
{
    int mark = start;

    int pivot = p[start];

    for (int i = start + 1; i <= end; i++) {
        if (p[i] < pivot) {
            mark++;
            int temp = p[mark];
            p[mark] = p[i];
            p[i] = temp;
        }
    }

    p[start] = p[mark];
    p[mark] = pivot;
    
    return mark;
}

int quick_sort(int p[], int start, int end)
{
    if (start >= end) {
        return 0;
    }

    int pivot = partition(p, start, end);

    quick_sort(p, start, pivot - 1);
    quick_sort(p, pivot + 1, end);

    return 0;
}

int main(int argc, char *argv[])
{
    int i;

    /* seek init */
    srand((unsigned int)time(NULL));

    /* rand() % (b - a + 1) + a, rang[a,b] */
    for (i = 0; i < N; i++) {
        data[i] = rand() % (b - a + 1) + a;
    }

    /* print init data */
    printf("init data is    :\t");
    print_data(data, N);

    /* start sorting */
    quick_sort(data, 0, N - 1);

    /* print sorted data */
    printf("sorted data is  :\t");
    print_data(data, N);
    return 0;
}