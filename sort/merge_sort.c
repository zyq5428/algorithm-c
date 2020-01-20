#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int hill_sort(int p[], int n)
{
    int gap = 1;
    while (gap < n) {
        gap = gap * 3 + 1;
    }
    printf("init gap is : %d\n", gap);
    while (gap > 0) {
        for (int i = gap; i < n; i++) {
            int temp = p[i];
            int j = i - gap;
            while (j >= 0 && p[j] > temp) {
                p[j + gap] = p[j];
                j -= gap;
            }
            p[j + gap] = temp;
            printf("current data is :\t");
            print_data(p, n);
        }
        gap = gap / 3;
        printf("current gap is : %d\n", gap);
    }

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
    hill_sort(data, N);

    /* print sorted data */
    printf("sorted data is  :\t");
    print_data(data, N);
    return 0;
}