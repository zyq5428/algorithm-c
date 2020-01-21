#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 12
#define a 100
#define b 999

int data[N];

void print_data(int p[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d\t", p[i]);
    }
    printf("\n");
}

int count_sort(int p[], int n)
{
    int max = p[0];

    for (int i = 1; i < n; i++) {
        if (p[i] > max) {
            max = p[i];
        }
    }

    char *count = malloc((size_t)(max + 1));

    for (int i = 0; i < n; i++) {
        count[p[i]]++;
        p[i] = 0;
    }

    int index = 0;

    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            p[index++] = i;
            count[i]--;
        }
    }

    free(count);

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
    count_sort(data, N);

    /* print sorted data */
    printf("sorted data is  :\t");
    print_data(data, N);
    return 0;
}