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

int sink(int p[], int index, int n)
{
    int left_child = 2 * index + 1;
    int right_child = 2 * index + 2;
    int present = index;

    if (left_child < n && p[left_child] > p[present]) {
        present = left_child;
    }

    if (right_child < n && p[right_child] > p[present]) {
        present = right_child;
    }

    if (present != index) {
        int temp = p[index];
        p[index] = p[present];
        p[present] = temp;

        sink(p, present, n);
    }
}

int build_heap(int p[], int n)
{
    for (int i = n / 2; i >= 0; i--) {
        sink(p, i, n);
    }
}

int heap_sort(int p[], int n)
{
    build_heap(p, n);

    for (int i = n - 1; i > 0; i--) {
        int temp = p[0];
        p[0] = p[i];
        p[i] = temp;

        n--;

        sink(p, i, n);
    }

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
    heap_sort(data, N);

    /* print sorted data */
    printf("sorted data is  :\t");
    print_data(data, N);
    return 0;
}