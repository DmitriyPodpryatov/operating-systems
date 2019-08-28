#include <stdio.h>
#include <string.h>

#define SIZE 100

void print_reverse(char*);

int main() {

    char string[SIZE];
    printf("Input string:\n");
    scanf("%s", string);
    printf("Reversed string:\n");
    print_reverse(string);

    return 0;

}

void print_reverse(char* s) {
    int len = strlen(s);
    for (int i = len - 1; i >= 0; i--) {
        putchar(s[i]);
    }
}