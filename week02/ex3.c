#include <stdio.h>

void print_triangle(int);
void print_spaces(int);

void figure1(int);
void figure2(int);
void figure3(int);

int main(int argc, char *argv[]) {

    int n;
    sscanf(argv[1], "%d", &n);
    print_triangle(n);
    printf("\n");

    // For exercise 5
    figure1(n);
    printf("\n");
    figure2(n);
    printf("\n");
    figure3(n);

    return 0;
    
}

// Function to exercise 3
void print_triangle(int n) {
    int max_spaces = 2*n; // Distance to the first star in the first row

    for (int i = 1; i <= n; i++) {
        print_spaces(max_spaces - 2*i); // Print spaces before stars

        for (int j = 0; j < 2*i - 1; j++) {
            printf("* "); // Print star+space
        }

        printf("\n");
    }
}

void print_spaces(int n) {
    for (int i = 0; i < n; i++) {
        printf(" ");
    }
}

// Functions to exercise 5
void figure1(int n) {
    for (int i = 1; i <= n; i++) {

        for (int j = 0; j < i; j++) {
            printf("*"); // Print stars
        }

        printf("\n");
    }
}


void figure2(int n) {
    int max; // Max number of stars per row
    int odd; // Flag if odd
    if (n % 2 == 1) {
        max = n/2 + 1;
        odd = 1;
    } 
    else {
        max = n/2;
        odd = 0;
    }
    // First half of figure
    for (int i = 1; i <= max; i++) {
        
        for (int j = 0; j < i; j++) {
            printf("*");
        }

        printf("\n");
    }
    // Second half of figure
    for (int i = max - odd; i >= 1; i--) {

        for (int j = 0; j < i; j++) {
            printf("*");
        }

        printf("\n");
    }
}


void figure3(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("*");
        }
        printf("\n");
    }
}