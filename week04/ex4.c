#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define SIZE 100

int main(int argc, char* argv[]) {

    // Read input and put it into system() function
    char input[SIZE];

    char *newargv[] = {argv[1], "hello", "world", NULL};
    char *newenviron[] = {NULL};
    execve(argv[1], newargv, newenviron);
    perror("execve");

    while (1) {        
        scanf("%s", input);

        if (strcmp(input, "^Z") == 0) {
            return 0;
        }

        system(input);
    }

}