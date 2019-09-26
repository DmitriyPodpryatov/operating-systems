#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZE 50

char s1[SIZE] = "Some text";
char s2[SIZE];

int main() {

    int pipedes[2];

    int pid;

    // Create pipe and check its correctness
    if (pipe(pipedes)) {
        exit(1);
    }

    // fork

    // Parent
    if ((pid = fork()) > 0) {
        // Close read-descriptor
        close(pipedes[0]);

        // Write pipe
        write(pipedes[1], s1, SIZE);

        // Close write-descriptor
        close(pipedes[1]);
    }
    // Child
    else {
        // Close write-descriptor
        close(pipedes[1]);

        // Transfer message
        read(pipedes[0], s2, SIZE);

        // Close read-descriptor
        close(pipedes[0]);
    }

    printf("%s\n", s2);

    return 0;

}