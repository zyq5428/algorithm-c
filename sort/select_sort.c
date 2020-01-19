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

int select_sort(int p[], int n)
{
    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (p[j] < p[min]) {
                min = j;
            }
        }
        int temp = p[i];
        p[i] = p[min];
        p[min] = temp;
        printf("current data is :\t");
        print_data(p, n);
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
    select_sort(data, N);

    /* print sorted data */
    printf("sorted data is  :\t");
    print_data(data, N);
    return 0;
}