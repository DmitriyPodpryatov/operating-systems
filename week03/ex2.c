#include <stdio.h>

void bubble_sort(int*, int);

int main() {

    int a[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    printf("Before sorting\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }

    bubble_sort(a, 10);

    printf("\nAfter sorting\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }

    return 0;

}

void bubble_sort(int* a, int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = len - 1; j > i; j--) {
            if (a[j] < a[j - 1]) {
                int temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }
        }
    }
}