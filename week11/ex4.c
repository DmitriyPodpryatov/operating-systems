#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>

int main() {

    char *path = "ex1.txt";
    char *pathmem = "ex1.memcpy.txt";

    int fd;
    int fdmem;

    // Open files for reading and writing
    if (((fd = open(path, O_RDONLY)) == -1) || ((fdmem = open(pathmem, O_RDWR)) == -1)) {
        printf("Cannot open file\n");
        exit(1);
    }

    // Get the size of the file
    struct stat fileStat;
    if (stat(path, &fileStat) == -1) {
        printf("Cannot get stat\n");
    }

    off_t size = fileStat.st_size;

    // Create mappings
    char *addr = mmap(NULL, size, PROT_READ, MAP_SHARED, fd, 0);
    char *addrmem = mmap(NULL, size, PROT_WRITE, MAP_SHARED, fdmem, 0);

    if ((addr == MAP_FAILED) || (addrmem == MAP_FAILED)) {
        printf("Error during mapping\n");
        exit(1);
    }

    // Buffer to store the content
    char buffer[size];

    // Truncate the size of file
    ftruncate(fdmem, size);

    // Copy the content
    memcpy(addrmem, addr, size);

    // Remove mapping and cloose the files
    munmap(addr, size);
    munmap(addrmem, size);
    close(fd);
    close(fdmem);

    return 0;

}