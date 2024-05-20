#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 1000000000 // 1000000000

void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

double wtime()
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec + ts.tv_nsec * 1E-9;
}

void partition(int *v, int *i, int *j, int low, int high)
{
    *i = low;
    *j = high;
    int pivot = v[(low + high) / 2];
    do
    {
        while (v[*i] < pivot)
            (*i)++;
        while (v[*j] > pivot)
            (*j)--;
        if (*i <= *j)
        {
            swap(&(v[*i]), &(v[*j]));
            (*i)++;
            (*j)--;
        }
    } while (*i <= *j);
}

void quicksort(int *v, int low, int high)
{
    int i, j;
    // print_arr(v);
    partition(v, &i, &j, low, high);
    if (low < j)
        quicksort(v, low, j);
    if (i < high)
        quicksort(v, i, high);
}

int get_rand_value()
{
    return rand() % 100;
}

void print_array(int *array)
{
    for (int i = 0; i < SIZE; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main()
{
    int *array = malloc(sizeof(int) * SIZE);
    for (int i = 0; i < SIZE; i++)
        array[i] = get_rand_value();
    // print_array(array);
    double time = wtime();
    quicksort(array, 0, SIZE - 1);
    time = wtime() - time;
    // print_array(array);
    printf("%lf\n", time);
    return 0;
}