#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int main() {

    // Read input and put it into system() function
    char input[SIZE];

    while (1) {
        
        scanf("%s", input);

        if (strcmp(input, "^Z") == 0) {
            return 0;
        }

        system(input);
    }

}