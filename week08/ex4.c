#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/resource.h>

// "si" and "so" (amount of memory Swapped In and Out) numbers change only when MB is near the 1000
// when "so" become to grow, the pc freezes for several seconds.
#define MB 10

int main() {

    char *ptr;
    struct rusage usage;

    for (int i = 0; i < 10; i++) {
        ptr = malloc(MB * 1024 * 1024);
        memset(ptr, '0', MB * 1024 * 1024);
        getrusage(RUSAGE_SELF, &usage);
        printf("Memory usage %ld (KB)\n", usage.ru_maxrss);
        sleep(1);
    }

    return 0;

}