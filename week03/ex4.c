#include <stdio.h>

void quick_sort(int*, int, int);
int partition(int*, int, int);

int main() {

    int a[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    printf("Before sorting\n");
    for(int i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }

    quick_sort(a, 0, 9);

    printf("\nAfter sorting\n");
    for(int i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }

    return 0;

}

void quick_sort(int* a, int lo, int hi) {
    if (lo < hi) {
        int p = partition(a, lo, hi);
        quick_sort(a, lo, p);
        quick_sort(a, p + 1, hi);
    }
}

int partition(int* a, int lo, int hi) {
    // Choose a pivot
    int pivot = a[lo + (hi - lo)/2];
    while(1) {
        // Place all elements less than pivot on the left side of pivot
        // And all elements greater than pivot on the right side
        while(a[lo] < pivot) {
            lo++;
        }
        while(a[hi] > pivot) {
            hi--;
        }

        if (lo >= hi) {
            return hi;
        }

        int temp = a[lo];
        a[lo] = a[hi];
        a[hi] = temp;

        lo++;
        hi--;
    }
}