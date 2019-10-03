#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 15

int main() {

    // Allocate memory
    char **s = malloc(SIZE * sizeof(char *));
    for (int i = 0; i < SIZE; i++) {
        s[i] = malloc(SIZE * sizeof(char));
    }
    char foo[] = "Hello World";

    // Copy strings
    printf("s is ");
    for (int i = 0; i < SIZE && foo[i] != '\0'; i++) {
        s[i][0] = foo[i];
        putchar(s[i][0]);
    }
    putchar('\n');

    strcpy(s[0], foo);
    printf("s[0] is %s\n", s[0]);

    /*
    for (int i = 0; i < SIZE; i++) {
        printf("%s\n", s[i]); // Check array
    }
    */

    // Free the memory
    for (int i = 0; i < SIZE; i++) {
        free(s[i]);
    }
    free(s);

    return(0);
}

/*
The array will have the following content:

Hello World
e
l
l
o
 
W
o
r
l
d

*/