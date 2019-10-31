#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main() {

    // Buffer
    char buf[SIZE];

    // Set line buffering on stdout
    setvbuf(stdout, buf, _IOLBF, SIZE);

    // Print "Hello"
    printf("H");
    sleep(1);
    printf("e");
    sleep(1);
    printf("l");
    sleep(1);
    printf("l");
    sleep(1);
    printf("o");
    sleep(1);
    printf("\n");

    return 0;

}
/*
    The program will wait five seconds while filling up buffer, then buffer encounters new line symbol, and it is printed out.
*/