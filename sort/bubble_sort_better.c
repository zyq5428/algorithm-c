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

int bubble(int p[], int n)
{
    bool is_sort = true;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            int temp = 0;
            if (p[j] < p[j + 1]) {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
                is_sort = false;
            }
        }
        if (is_sort) {
            break;
        }
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
    printf("init data is \t:\t");
    print_data(data, N);

    /* bubble sort */
    bubble(data, N);

    /* print sorted data */
    printf("sorted data is \t:\t");
    print_data(data, N);
    return 0;
}