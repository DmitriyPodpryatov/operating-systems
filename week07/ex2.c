#include <stdio.h>
#include <stdlib.h>

int main() {

    int n;
    
    printf("Enter the size of array\n");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Wrong size\n");
        exit(1);
    }

    int* a = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        a[i] = i;
        printf("%d ", a[i]);
    }
    printf("\n");

    free(a);

    return 0;

}