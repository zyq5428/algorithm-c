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

int insert_sort(int p[], int n)
{
    for (int i = 1; i < n; i++) {
        int value = i;
        int j = 0;
        for (j = i - 1; j >= n; j--) {
            if (p[j] > value) {
                p[j + 1] = p[j];
            } else {
                break;
            }
        }
        p[j + 1] = value;
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
    insert_sort(data, N);

    /* print sorted data */
    printf("sorted data is  :\t");
    print_data(data, N);
    return 0;
}