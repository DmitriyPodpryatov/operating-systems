#include <stdio.h>

void swap(int*, int*);

int main() {

    int m, n;
    printf("Input two integers:\nm = ");
    scanf("%d", &m);
    printf("n = ");
    scanf("%d", &n);

    swap(&m, &n);

    printf("After swap:\nm = %d\nn = %d\n", m, n);

    return 0;

}

void swap(int* x, int* y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}