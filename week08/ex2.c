#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// "si" and "so" (amount of memory Swapped In and Out) numbers change only when MB is near the 1000
// when "so" become to grow, the pc freezes for several seconds.
#define MB 10

int main() {

    char *ptr;

    for (int i = 0; i < 10; i++) {
        ptr = malloc(MB * 1024 * 1024);
        memset(ptr, '0', MB * 1024 * 1024);
        sleep(1);
    }

    return 0;

}