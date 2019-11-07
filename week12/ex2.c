#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 10000

int main(int argc, char *argv[]) {

    // Check if there is a flag
    int override;
    if (strcmp(argv[1], "-a") == 0) {
        override = 1;
    }
    else {
        override = 0;
    }

    // Output file
    FILE *output;

    // Read from stdin
    char buffer[BUFFER_SIZE];
    // Read byte by byte
    char c;
    int i = 0;
    while (read(STDIN_FILENO, &c, 1) > 0) {
        buffer[i] = c;
        i++;
    }
    buffer[i] = '\0';
    
    // Write to stdout
    write(STDOUT_FILENO, buffer, i);

    // Write to files
    int j;
    if (override) {
        j = 2;
    }
    else {
        j = 1;
    }
    
    for (; j < argc; j++) {
        if (override) {
            output = fopen(argv[j], "a");
        }
        else {
            output = fopen(argv[j], "w");
        }
        fwrite(buffer, sizeof(char), i, output);
        fclose(output);
    }

    return 0;

}