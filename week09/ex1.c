/*
 Since we are not given the behavior of Reference bits,
 I assume that R bit is 1 only when the page is referenced, and is 0 otherwise
*/
#include <stdio.h>
#include <stdlib.h>

#define BUFFER 50

FILE *input;

// Convert string to int
int my_atoi(char* s) {
    int result = 0;
    int i = 0;
    while (s[i] != '\0') {
        result = result * 10 + (s[i++] - '0');
    }
    return result;
}

int main(int argc, char* argv[]) {

    if (argc < 2) {
        printf("No parameter error\n");
        exit(1);
    }

    int size = my_atoi(argv[1]);
    // Page frames and corresponding counters
    int page_frames[size];
    unsigned char counters[size];
    for (int i = 0; i < size; i++) {
        page_frames[i] = 0;
        counters[i] = 0;
    }

    // Read file
    input = fopen("Lab 09 input.txt", "r");

    char c;
    char s[BUFFER];
    int i = 0;
    // Stores page from file 
    int page;

    // Points to the location of next free cell (if any)
    int pointer = 0;

    // Hit and miss numbers for calculating the hit/miss ration
    int hit = 0;
    int miss = 0;
    while ((c = fgetc(input)) != EOF) {
        if (c == ' ' || c == '\n') {
            // Read number
            s[i] = '\0';
            i = 0;
            page = my_atoi(s);

            // Stores 1 if page is already in memory
            int in_memory = 0;
            // Change counters
            for (int j = 0; j < size; j++) {
                if (page_frames[j] == page) {
                    // If page is in memory, R bit is 1
                    // Shift counter to the right and set the leftmost bit to 1
                    counters[j] = counters[j] / 2;
                    counters[j] += 128; // 128 = 2^7, char is 8 bits. So this line sets the leftmost bit to 1.
                    in_memory = 1;
                    // Increase hit variable
                    hit++;
                }
                else {
                    // For all other pages R bit is 0
                    // Just shift to the right
                    counters[j] = counters[j] / 2;
                }
            }
            // If the page is not in memory, 
            if (!in_memory) {
                // If list is not full, write page to the free cell
                if (pointer < size) {
                    page_frames[pointer++] = page;
                }
                else {
                    // If list if full, search for the lowest counter, and replace it by new page
                    unsigned char min = counters[0];
                    int index = 0;
                    for (int j = 0; j < size; j++) {
                        if (counters[j] < min) {
                            min = counters[j];
                            index = j;
                        }
                    }
                    page_frames[index] = page;
                    counters[index] = 128;
                }
                // Increase miss variable
                miss++;
            }
            /* Print current page frames in a line
            for (int j = 0; j < size; j++) {
                printf("%d ", page_frames[j]);
            }
            printf("\n");
            */
        }
        else {
            // Add digit to buffer
            s[i++] = c;
        }
    }

    fclose(input);

    printf("Hit ratio %.3f\nMiss ratio %.3f\n", (hit*1.0f)/(hit + miss), (miss*1.0f)/(hit + miss));

    return 0;

}

/*
    Results for Hit/Miss ratios (for total of 1000 page references):
                  | Hit Ratio | Miss Ratio
    10 Page Frames| 0.009     | 0.991
    50 Page Frames| 0.051     | 0.949
   100 Page Frames| 0.093     | 0.907
  1000 Page Frames| 0.375     | 0.625
*/