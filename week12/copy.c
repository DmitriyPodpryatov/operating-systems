#include <stdio.h>   
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {

    // Open files
    int fdA, fdB;

    if (argc != 3) {
        printf("Wrong number of parameters\n");
    }

    if (((fdA = open(argv[1], O_RDONLY)) == -1) || ((fdB = open(argv[2], O_RDWR)) == -1)) {
        printf("Cannot open file\n");
        exit(1);
    }

    // Copying the content
    char buf[BUF_SIZE];
    ssize_t numRead;
    
    while ((numRead = read(fdA, buf, BUF_SIZE)) > 0) {
        if (write(fdB, buf, numRead) != numRead) {
            printf("Error during copying");
            exit(1);
        }
    }
    

    close(fdA);
    close(fdB);

    return 0;

}