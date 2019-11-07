#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SIZE 21

int main() {

    // Output file
    FILE *output;
    // Open output file
    output = fopen("ex1.txt", "w");

    // Open /dev/random file for reading
    int fd = open("/dev/random", O_RDONLY);

    if (fd == -1) {
        printf("Cannot opne file\n");
        exit(1);
    }

    char buffer[SIZE];

    // Read data in buffer (/dev/random may return less bytes than it was asked)
    size_t i = 0;
    while (i < SIZE) {
        ssize_t length = read(fd, buffer + i, SIZE - i);
        if (length < 0) {
            printf("Error during reading in\n");
        }
        i += length;
    }
    
    // Set last symbol to make it a string
    buffer[SIZE - 1] = '\0';

    // Write result to output file
    fprintf(output, "%s\n", buffer);

    // Close files
    close(fd);
    fclose(output);

    return 0;

}