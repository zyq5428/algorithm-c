#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define a 0
#define b 99

int data[N];
int temp_data[N];

void print_data(int p[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d\t", p[i]);
    }
    printf("\n");
}

int merge(int p[], int temp_p[], int start, int mid, int end)
{
    printf("temp data is \t:\t");
    for ( int s = start; s <= end; s++) {
        temp_p[s] = p[s];
        printf("%d\t", p[s]);
    }
    printf("\n");
    
    int left = start;
    int right = mid + 1;

    for (int k = start; k <= end; k++) {
        if (left > mid) {
            p[k] = temp_p[right++];
        } else if (right > end) {
            p[k] = temp_p[left++];
        } else if (temp_p[left] > temp_p[right]) {
            p[k] = temp_p[right++];
        } else {
            p[k] = temp_p[left++];
        }
    }
}

int merge_sort(int p[], int temp_p[], int start, int end)
{
    if (start >= end) {
        return 0;
    }

    int mid = start + (end - start) / 2;

    /* start split left */
    printf("start split left:\t%d - %d\n", start, mid);
    merge_sort(p, temp_p, start, mid);

    /* start split right */
    printf("start split right:\t%d - %d\n", mid + 1, end);
    merge_sort(p, temp_p, mid + 1, end);

    /* start merge */
    printf("start merge\t: %d - %d -%d\n", start, mid, end);
    merge(p, temp_p, start, mid, end);

    printf("current data is :\t");
    print_data(p, N);

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
    merge_sort(data, temp_data, 0, N-1);

    /* print sorted data */
    printf("sorted data is  :\t");
    print_data(data, N);
    return 0;
}