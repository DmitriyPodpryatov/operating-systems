#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <string.h>

#define STRING "This is a nice day"

int main() {

    char *path = "ex1.txt";

    int fd;

    // Open file in read/write mode
    if ((fd = open(path, O_RDWR)) == -1) {
        printf("Cannot open file\n");
        exit(1);
    }

    // Get the size of the file
    struct stat fileStat;
    if (stat(path, &fileStat) == -1) {
        printf("Cannot get stat\n");
    }

    off_t size = fileStat.st_size;

    // Create mapping
    char *addr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    if (addr == MAP_FAILED) {
        printf("Error during mapping\n");
        exit(1);
    }

    // Truncate the size of file
    ftruncate(fd, strlen(STRING));

    // Change the string
    strcpy(addr, STRING);

    // Remove mapping and close the file
    munmap(addr, size);
    close(fd);

    return 0;

}