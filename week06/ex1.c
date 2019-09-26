#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZE 50

char s1[SIZE] = "Some text";
char s2[SIZE];

int main() {

    int pipedes[2];

    // Create pipe and check its correctness
    if (pipe(pipedes)) {
        exit(1);
    }

    // Write pipe
    write(pipedes[1], s1, SIZE);

    // Transfer message
    read(pipedes[0], s2, SIZE);

    printf("%s\n", s2);

    return 0;

}